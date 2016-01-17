/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-14
* Description:
* * * * * * * * * * * * * * * */

#ifndef FILE_STREAM_H_
#define FILE_STREAM_H_

#include <string>
#include <MRT.h>

class FileStream
{
public:

    FileStream( );
    FileStream( std::string file , std::string mode );
    ~FileStream( );

    static bool         exist   ( std::string file );
    
    void                open    ( std::string file , std::string mode);
    void                close   ( );
    size_t              length  ( );
    size_t              write   ( uptr<MRT::Buffer> );
    size_t              write   ( const char* buffer ,
                                  size_t buffer_size );
    size_t              seek    ( size_t pos );
    uptr<MRT::Buffer>   read    ( size_t pos , size_t size );
    uptr<MRT::Buffer>   read    ( size_t size );
    size_t              position( );

private:

    FILE*   file_   = nullptr;
    size_t  offset_ = 0;
    size_t  length_ = 0;
};

#endif // !FILE_STREAM_H_
