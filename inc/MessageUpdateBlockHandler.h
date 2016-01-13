/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description: handler for MessageUpdateBlock
* * * * * * * * * * * * * * * */

#ifndef MESSAGEUPDATEBLOCK_HANDLER_
#define MESSAGEUPDATEBLOCK_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ProtocolSession.h>
#include <google/protobuf/message.h>
#include <MessageUpdateBlock.pb.h>

static int MessageUpdateBlockHandler( ProtocolSession * session , uptr<MessageUpdateBlock> msg )
{
    return 0;
}

#endif

// !MESSAGEUPDATEBLOCK_HANDLER_
