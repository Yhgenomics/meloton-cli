/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-21
* Description: handler for MessagePutAccept
* * * * * * * * * * * * * * * */

#ifndef MESSAGEPUTACCEPT_HANDLER_
#define MESSAGEPUTACCEPT_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ProtocolSession.h>
#include <google/protobuf/message.h>
#include <MessagePutAccept.pb.h>

#include <PutSession.h>

static int MessagePutAcceptHandler( ProtocolSession * session , uptr<MessagePutAccept> msg )
{
    PutSession* ps = ( PutSession* ) session;

    if ( ps == nullptr )
    {
        return -1;
    }

    if ( msg->size( ) == 0 )
    {
        return -1;
    }

    ps->send_data( );

    return 0;
}

#endif

// !MESSAGEPUTACCEPT_HANDLER_
