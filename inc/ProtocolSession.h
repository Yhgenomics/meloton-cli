/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description:
* * * * * * * * * * * * * * * */

#ifndef PROTOCOL_SESSION_H_
#define PROTOCOL_SESSION_H_

#include <MRT.h>
#include <google/protobuf/message.h>

class ProtocolSession :
    public MRT::Session
{
public:

    void send_message( uptr<::google::protobuf::Message> message );
    virtual void on_connect ( )                        override;
    virtual void on_read    ( uptr<MRT::Buffer> data ) override;
    virtual void on_write   ( uptr<MRT::Buffer> data ) override;
    virtual void on_close   ( )                        override;

private:

    enum ParseState
    {
        kHead = 1,
        kLength,
        kBody
    };

    MRT::CircleBuffer   circle_buffer_;
    ParseState          parse_state_ = ParseState::kHead;
    size_t              body_length_ = 0;

};

#endif // !PROTOCOL_SESSION_H_
