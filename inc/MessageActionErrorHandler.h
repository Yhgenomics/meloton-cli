/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description: handler for MessageActionError
* * * * * * * * * * * * * * * */

#ifndef MESSAGEACTIONERROR_HANDLER_
#define MESSAGEACTIONERROR_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ProtocolSession.h>
#include <google/protobuf/message.h>
#include <MessageActionError.pb.h>

static int MessageActionErrorHandler( ProtocolSession * session , uptr<MessageActionError> msg )
{
    Logger::error( "%d:%s" , msg->code( ) , msg->message( ).c_str() );
    return 1;
}

#endif

// !MESSAGEACTIONERROR_HANDLER_
