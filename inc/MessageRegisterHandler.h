/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description: handler for MessageRegister
* * * * * * * * * * * * * * * */

#ifndef MESSAGEREGISTER_HANDLER_
#define MESSAGEREGISTER_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ProtocolSession.h>
#include <google/protobuf/message.h>
#include <MessageRegister.pb.h>

static int MessageRegisterHandler( ProtocolSession * session , uptr<MessageRegister> msg )
{
    return 0;
}

#endif

// !MESSAGEREGISTER_HANDLER_
