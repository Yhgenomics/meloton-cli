/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description: handler for MessageRequestGet
* * * * * * * * * * * * * * * */

#ifndef MESSAGEREQUESTGET_HANDLER_
#define MESSAGEREQUESTGET_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ProtocolSession.h>
#include <google/protobuf/message.h>
#include <MessageRequestGet.pb.h>

static int MessageRequestGetHandler( ProtocolSession * session , uptr<MessageRequestGet> msg )
{
    return 0;
}

#endif

// !MESSAGEREQUESTGET_HANDLER_
