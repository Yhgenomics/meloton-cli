/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description: handler for MessagePut
* * * * * * * * * * * * * * * */

#ifndef MESSAGEPUT_HANDLER_
#define MESSAGEPUT_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ProtocolSession.h>
#include <google/protobuf/message.h>
#include <MessagePut.pb.h>

static int MessagePutHandler( ProtocolSession * session , uptr<MessagePut> msg )
{
    return 0;
}

#endif

// !MESSAGEPUT_HANDLER_
