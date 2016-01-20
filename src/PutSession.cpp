#include <PutSession.h>
#include <MessagePut.pb.h>
#include <Variable.h>

void PutSession::on_connect( )
{
    Variable::file_stream.open( Variable::local_path , "rb" );

    index_      = Variable::token->index( Variable::block_index );
    token_      = Variable::token->token( Variable::block_index );
    offset_     = Variable::token->offset( Variable::block_index );
    block_size_ = Variable::token->size( Variable::block_index );
    f_offset_   = 0;

    Variable::file_stream.seek( offset_ );
    send_data( );
}

void PutSession::on_write( uptr<MRT::Buffer> data )
{
    send_data( );
}

void PutSession::send_data( )
{
    Logger::sys( "Thread[%lld] Send Data" , std::this_thread::get_id() );
        
    const size_t len = 1024*10;
    size_t send_size = block_size_ > len ? len : block_size_;
    auto data = Variable::file_stream.read( send_size );
    
    if ( data == nullptr )
    {
        Logger::error( "Data is nullptr , disconnecting..." );
        this->close( );
        return;
    }

    if ( block_size_ == 0 || send_size == 0 )
    {
        this->close( );
        return;
    }

    uptr<MessagePut> msg = make_uptr( MessagePut ); 
    msg->set_index( index_ );
    msg->set_token( token_ );
    msg->set_size( data->size() );
    msg->set_offset( f_offset_ );
    msg->set_data( data->data( ) , data->size( ) );
    this->send_message( move_ptr( msg ) );

    f_offset_+=send_size;
    block_size_ -= send_size;
}
