#include <GetSession.h>
#include <MessageGet.pb.h>
#include <Variable.h>

size_t GetSession::offset_ = 0;

void GetSession::on_connect( )
{
    this->total_size_ = Variable::token->size( Variable::block_index );
    this->fs_ = &Variable::file_stream;
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
    total_size_     -= s;
    offset_         += s;
    local_offset_   += s;

    fs_->seek( offset_ );
}

FileStream * GetSession::file_stream( )
{
    return this->fs_;
}
 
size_t GetSession::offset( )
{
    return this->local_offset_ + offset_;
}
