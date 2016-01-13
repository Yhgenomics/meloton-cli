/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description: handler for MessageAccept
* * * * * * * * * * * * * * * */

#ifndef MESSAGEACCEPT_HANDLER_
#define MESSAGEACCEPT_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ProtocolSession.h>
#include <google/protobuf/message.h>
#include <MessageAccept.pb.h>

static int MessageAcceptHandler( ProtocolSession * session , uptr<MessageAccept> msg )
{
    return 0;
}

#endif

// !MESSAGEACCEPT_HANDLER_
