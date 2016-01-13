#include <ProtocolSession.h>
#include <MessageUtils.h>

void ProtocolSession::on_connect( )
{

}

void ProtocolSession::send_message( uptr<::google::protobuf::Message> message )
{ 
    uptr<MRT::Buffer> head      = make_uptr( MRT::Buffer , "YH" );
    uptr<MRT::Buffer> length    = make_uptr( MRT::Buffer , 4 );
    uptr<MRT::Buffer> body      = MessageUtils::build( message.get( ) );

    *( ( int* ) length->data( ) ) = ( int ) body->size( );
    
    this->send( move_ptr( head ) );
    this->send( move_ptr( length ) );
    this->send( move_ptr( body ) );
}

void ProtocolSession::on_read( uptr<MRT::Buffer> data )
{

}

void ProtocolSession::on_write( uptr<MRT::Buffer> data )
{

}

void ProtocolSession::on_close( )
{

}
