/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description: handler for MessageRequestGetToken
* * * * * * * * * * * * * * * */

#ifndef MESSAGEREQUESTGETTOKEN_HANDLER_
#define MESSAGEREQUESTGETTOKEN_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ProtocolSession.h>
#include <google/protobuf/message.h>
#include <MessageRequestGetToken.pb.h>

static int MessageRequestGetTokenHandler( ProtocolSession * session , uptr<MessageRequestGetToken> msg )
{
    return 0;
}

#endif

// !MESSAGEREQUESTGETTOKEN_HANDLER_
