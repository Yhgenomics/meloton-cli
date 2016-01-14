/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description: handler for MessageToken
* * * * * * * * * * * * * * * */

#ifndef MESSAGETOKEN_HANDLER_
#define MESSAGETOKEN_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ProtocolSession.h>
#include <google/protobuf/message.h>
#include <MessageToken.pb.h>
#include <Variable.h>

static int MessageTokenHandler( ProtocolSession * session , uptr<MessageToken> msg )
{
    Variable::token = move_ptr( msg );
    session->close( );
    return 0;
}

#endif

// !MESSAGETOKEN_HANDLER_
