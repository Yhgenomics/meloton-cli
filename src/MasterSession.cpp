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
        FileStream fs;
        fs.open( Variable::local_path , "rb+" );
        size_t size = fs.length( );


        uptr<MessageRequestPut> msg = make_uptr( MessageRequestPut );
        msg->set_path( Variable::remote_path );
        msg->set_request_id( MRT::UUID::create( ) );
        msg->set_size( fs.length( ) );
        this->send_message( move_ptr( msg ) );
    }
    else if( Variable::mode == "g" )
    {

    }
    else
    {
        this->close( );
    }
}
