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
    this->circle_buffer_.push( move_ptr( data ) );
    while ( true )
    {
        switch ( this->parse_state_ )
        {
            case ParseState::kHead:
                {
                    auto buf = circle_buffer_.pop( 2 );

                    if ( buf == nullptr )return;

                    if ( buf->data( )[0] == 'Y' &&
                         buf->data( )[1] == 'H' )
                    {
                        this->parse_state_ = ParseState::kLength;
                    }
                }break;
            case ParseState::kLength:
                {
                    auto buf = circle_buffer_.pop( 4 );

                    if ( buf == nullptr )return;

                    int len = *( ( int * ) buf->data( ) );

                    if ( len > MAX_CIRCLE_BUFFER_SIZE )
                    {
                        this->parse_state_ = ParseState::kHead;
                        break;
                    }

                    body_length_        = len;
                    this->parse_state_  = ParseState::kBody;

                }break;
            case ParseState::kBody:
                {
                    auto buf = circle_buffer_.pop( body_length_ );

                    if ( buf == nullptr )return;

                    auto result = MessageUtils::handle( this ,
                                                        buf->data( ) ,
                                                        buf->size( ) );

                    if ( result < 0 )
                    {
                        this->close( );
                        return;
                    }

                    body_length_        = 0;
                    this->parse_state_  = ParseState::kHead;
                }break;
            default:
                break;
        }
    }
}

void ProtocolSession::on_write( uptr<MRT::Buffer> data )
{

}

void ProtocolSession::on_close( )
{

}
