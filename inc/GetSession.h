/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-17
* Description:
* * * * * * * * * * * * * * * */

#ifndef GET_SESSION_H_
#define GET_SESSION_H_

#include <MRT.h>
#include <ProtocolSession.h>
#include <FileStream.h>

class GetSession :
    public ProtocolSession
{
public:
  
    virtual void on_connect ( ) override;
    virtual void on_write   ( uptr<MRT::Buffer> data ) override;
    virtual void on_close   ( )                        override;
    
    void send_req           ( );
    void receive_size       ( size_t s );
    FileStream* file_stream ( );
    size_t offset           ( );

private:

    size_t  local_offset_   = 0;
    static size_t offset_  ;
    size_t get_size_        = 1024*1024;
    size_t total_size_      = 0;
    FileStream* fs_;
};

#endif // !GET_SESSION_H_
