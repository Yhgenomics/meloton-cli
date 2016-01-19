/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description: handler for MessageBlockData
* * * * * * * * * * * * * * * */

#ifndef MESSAGEBLOCKDATA_HANDLER_
#define MESSAGEBLOCKDATA_HANDLER_

#include <string>
#include <memory>

#include <MRT.h>
#include <ProtocolSession.h>
#include <google/protobuf/message.h>
#include <MessageBlockData.pb.h>

#include <Variable.h>
#include <GetSession.h>

static int MessageBlockDataHandler( ProtocolSession * session , uptr<MessageBlockData> msg )
{
    GetSession* s = ( GetSession* ) session;

    if ( s == nullptr )
    {
        return -1;
    }

    Logger::sys( "Block Data Offset: %lld Size: %lld",
                 msg->offset(),
                 msg->size());

    s->file_stream()->write( msg->data( ).c_str( ) ,
                                 msg->data( ).size( ) );

    s->receive_size( msg->size( ) );
    s->send_req( );

    return 0;
}

#endif

// !MESSAGEBLOCKDATA_HANDLER_
