#include <GetSession.h>
#include <MessageGet.pb.h>
#include <Variable.h>

void GetSession::on_connect( )
{
    this->total_size_ = Variable::token->size( Variable::block_index );
    send_req( );
}

void GetSession::on_write( uptr<MRT::Buffer> data )
{

}

void GetSession::on_close( )
{

}

void GetSession::send_req( )
{
    auto index = Variable::block_index;
    auto token = Variable::token->token( index );

    uptr<MessageGet> msg = make_uptr( MessageGet );
    msg->set_index( 0 );
    msg->set_offset( local_offset_ );
    msg->set_size( total_size_ > get_size_ ? get_size_ : total_size_ );
    msg->set_token( token );

    this->send_message( move_ptr( msg ) );
}

void GetSession::receive_size( size_t s )
{
    total_size_             -= s;
    Variable::file_offset   += s;
    local_offset_           += s;

    Variable::ostream.seekp( Variable::file_offset , std::ios::beg );
    //Variable::file_stream.seek( offset_ );
} 
 
size_t GetSession::offset( )
{
    return this->local_offset_ + offset_;
}
