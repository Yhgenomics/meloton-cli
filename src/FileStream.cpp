#define _FILE_OFFSET_BITS 64

#ifdef _WIN32
#define ftello _ftelli64
#define fseeko _fseeki64
#else

#endif

#include <FileStream.h>
#include <stdio.h>

FileStream::FileStream( )
{

}

FileStream::FileStream( std::string file , std::string mode )
{
    open( file , mode );
}

FileStream::~FileStream( )
{
    if ( this->file_ != nullptr )
    {
        fclose( this->file_ );
    }
}

bool FileStream::exist( std::string file )
{
    auto f = fopen( file.c_str( ) , "rb+" );
    bool ret = f != nullptr;

    if ( ret )
    {
        fclose( f );
    }

    return ret;
}

void FileStream::open( std::string file , std::string mode )
{
    if ( this->file_ != nullptr )
    {
        fclose( this->file_ );
        return;
    } 

    this->file_ = fopen( file.c_str( ) , mode.c_str( ) );
    this->offset_ = 0;

    fseeko( this->file_ , 0 , SEEK_END );
    this->length_ = ftello( this->file_ );
    fseeko( this->file_ , 0 , SEEK_SET );

}

void FileStream::close( )
{
    if ( this->file_ == nullptr )
        return;

    fclose( this->file_ );
    this->file_ = nullptr;
}

size_t FileStream::seek( size_t pos )
{
    fseeko( this->file_ , pos , SEEK_SET );
    this->offset_ = pos;
    return this->offset_;
}

size_t FileStream::length( )
{
    return this->length_;
}

size_t FileStream::write( uptr<MRT::Buffer> buffer )
{
    if ( this->file_ == nullptr )
        return 0;

    auto writes = fwrite( buffer->data( ) , 
                          1 ,
                          buffer->size( ) , 
                          this->file_ );

    this->offset_ += writes;
    return writes;
}

size_t FileStream::write( const char* buffer ,
                          size_t buffer_size )
{
    if ( this->file_ == nullptr )
        return 0;

    auto writes = fwrite( buffer , 
                          1 ,
                          buffer_size , 
                          this->file_ );
    this->offset_ += writes;

    return writes;
}

uptr<MRT::Buffer> FileStream::read( size_t pos , size_t s )
{
    size_t size = s;

    if ( this->file_ == nullptr )
        return nullptr;

    if ( size == 0 )
        return nullptr;

    this->seek( pos );
    auto file_size = this->length( );
    long long delta = file_size - ( pos + size );

    if ( delta < 0 )
    {
        size += delta;
    }

    uptr<MRT::Buffer> ret = make_uptr( MRT::Buffer , size );
    this->offset_ += fread( ret->data( ) ,
                            sizeof(char) , 
                            size ,
                            this->file_ );
    return move_ptr( ret );
}

uptr<MRT::Buffer> FileStream::read( size_t s )
{
    size_t size = s;

    if ( this->file_ == nullptr )
        return nullptr;

    if ( size == 0 )
        return nullptr;

    auto file_size  = this->length( );
    long long delta = file_size - ( this->offset_ + size );

    if ( delta < 0 )
    {
        size += delta;
    }

    uptr<MRT::Buffer> ret = make_uptr( MRT::Buffer , size );

    const int BUF_SIZE = 1024;
    auto bytes2read = s;
    char buf[BUF_SIZE]= { 0 };
    while ( true )
    {
        int len = bytes2read > BUF_SIZE ? BUF_SIZE : bytes2read;

        auto reads = fread( buf ,
                            sizeof( char ) ,
                            len ,
                            this->file_ );

        if ( reads == 0 )
        {
            break;
        }

        this->offset_ += reads;

        ret->push( buf , reads );

        bytes2read -= reads;
    }
    
    return move_ptr( ret );
}

size_t FileStream::position( )
{
    return this->offset_;
}
