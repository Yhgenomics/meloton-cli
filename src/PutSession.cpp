#include <PutSession.h>
#include <MessagePut.pb.h>
#include <Variable.h>
#include <thread>

#define _FILE_OFFSET_BITS 64

#ifdef _WIN32
#define ftello _ftelli64
#define fseeko _fseeki64
#else

#endif

#include <FileStream.h>
#include <stdio.h>

void PutSession::on_connect( )
{
    file_ = fopen( Variable::local_path.c_str( ) , "rb" );
    
    if ( file_ == nullptr )
    {
        Logger::error( "Open file failed" );
        this->close( );
        return;
    }
    //Variable::file_stream.open( Variable::local_path , "rb" );

    index_      = Variable::token->index( Variable::block_index );
    token_      = Variable::token->token( Variable::block_index );
    offset_     = Variable::token->offset( Variable::block_index );
    block_size_ = Variable::token->size( Variable::block_index );
    f_offset_   = 0;

    fseeko( file_ , offset_ , SEEK_SET );

    //Variable::file_stream.seek( offset_ );
    send_data( );
}

void PutSession::on_write( uptr<MRT::Buffer> data )
{
    send_data( );
}

void PutSession::on_close( )
{
    if ( file_ != nullptr )
    {
        fclose( file_ );
    }
}

void PutSession::send_data( )
{
    const size_t len = 1024*1024;
    char* buffer = new char[len];
    size_t send_size = block_size_ > len ? len : block_size_;
    
    auto reads = fread( buffer , 1 , send_size , file_);

    if ( reads == 0 )
    {
        Logger::error( "Data is nullptr , disconnecting..." );
        this->close( );
        return;
    }

    send_size = reads;

    //auto data = Variable::file_stream.read( send_size );
    //if ( data == nullptr )
    //{
    //    Logger::error( "Data is nullptr , disconnecting..." );
    //    this->close( );
    //    return;
    //}
    //Logger::sys( "Read Block %lld" , data->size());

    if ( block_size_ == 0 || send_size == 0 )
    {
        this->close( );
        return;
    }

    uptr<MessagePut> msg = make_uptr( MessagePut ); 
    msg->set_index( 0 );
    msg->set_token( std::string( token_ ) );
    msg->set_size( reads );
    msg->set_offset( f_offset_ );
    msg->set_data( buffer , reads );

    this->send_message( move_ptr( msg ) );

    f_offset_ += send_size;
    block_size_ -= send_size;

    SAFE_DELETE( buffer );
}
