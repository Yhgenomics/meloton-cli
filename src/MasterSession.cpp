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
        Variable::istream.open( Variable::local_path , std::ios::in | std::ios::binary );
        Variable::istream.seekg( 0 , std::ios::end );
        size_t size = Variable::istream.tellg( );
        Logger::log( "Put File Size: %" , size );
        uptr<MessageRequestPut> msg = make_uptr( MessageRequestPut );
        msg->set_path( Variable::remote_path );
        msg->set_request_id( MRT::UUID::create( ) );
        msg->set_size( size );
        this->send_message( move_ptr( msg ) );

        Variable::istream.close( );
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
