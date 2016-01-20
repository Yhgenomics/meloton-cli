#include <MasterSession.h>
#include <MessageGet.pb.h>
#include <MessagePut.pb.h>
#include <MessageRequestGet.pb.h>
#include <MessageRequestPut.pb.h>
#include <Variable.h>
#include <FileStream.h>

void MasterSession::on_connect( )
{
    if ( Variable::mode == "p" )
    { 
        Variable::file_stream.open( Variable::local_path , "rb+" );
        size_t size = Variable::file_stream.length( ); 

        uptr<MessageRequestPut> msg = make_uptr( MessageRequestPut );
        msg->set_path( Variable::remote_path );
        msg->set_request_id( MRT::UUID::create( ) );
        msg->set_size( Variable::file_stream.length( ) );
        this->send_message( move_ptr( msg ) );
    }
    else if( Variable::mode == "g" )
    {
        uptr<MessageRequestGet> msg = make_uptr( MessageRequestGet );
        msg->set_path( Variable::remote_path );
        msg->set_request_id( MRT::UUID::create( ) );
        this->send_message( move_ptr( msg ) );
    }
    else
    {
        this->close( );
    }
}
