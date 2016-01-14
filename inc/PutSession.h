/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description:
* * * * * * * * * * * * * * * */

#ifndef PUT_SESSION_H_
#define PUT_SESSION_H_

#include <string>

#include <MRT.h>
#include <ProtocolSession.h>
#include <FileStream.h>

class PutSession :
    public ProtocolSession
{
public:

    virtual void on_connect ( ) override;
    virtual void on_write   ( uptr<MRT::Buffer> data ) override;

private:

    void send_data( );
    FileStream fs_;
    std::string token_;
    size_t offset_ = 0;
    size_t block_size_ = 0;
    size_t index_ = 0;
    size_t f_offset_ = 0;
};

#endif // !PUT_SESSION_H_