/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description: handler for MessageGet
* * * * * * * * * * * * * * * */

#ifndef MESSAGEGET_HANDLER_
#define MESSAGEGET_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ProtocolSession.h>
#include <google/protobuf/message.h>
#include <MessageGet.pb.h>

static int MessageGetHandler( ProtocolSession * session , uptr<MessageGet> msg )
{
    return 0;
}

#endif

// !MESSAGEGET_HANDLER_
