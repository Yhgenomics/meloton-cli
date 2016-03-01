#include "MRT.h"
#include <string>
#include <MasterConnector.h>
#include <PutConnector.h>
#include <GetConnector.h>
#include <Variable.h>
#include <FileStream.h>
#include <thread>
#include <MessagePut.pb.h>
#include <Path.h>

void print_help()
{
    fprintf( stdout , "YHFS\r\n" );
    fprintf( stdout , "Build %s\r\n" , __DATE__ );
    fprintf( stdout , "YHGenomics inc. Copyright\r\n" );
    fprintf( stdout , "========================================\r\n" );
    fprintf( stdout , "usage\r\n" );
    fprintf( stdout , "meloton-cli <mode> <master address> <remote file> ... <remote file> <local file> \r\n" );
    fprintf( stdout , "mode \r\n" );
    fprintf( stdout , "     g : download <remote file> \r\n" );
    fprintf( stdout , "     p : upload <local file> to <remote file> \r\n" );
    fprintf( stdout , "master address \r\n" );
    fprintf( stdout , "     master server ip address \r\n" );
}

int main( int argc , char* argv[] )
{

    MessagePut p;
    auto str = p.GetTypeName();

    Logger::sys( "Main Thread: %lld" , std::this_thread::get_id() );
    if ( argc < 3 )
    {
        print_help();
        return 1;
    }

    std::string mode        = std::string( argv[1] );
    std::string srv_addr    = std::string( argv[2] );
    //std::string r_path      = std::string( argv[3] );
    //std::string l_path      = std::string( argv[4] );

    Variable::master_ip     = srv_addr;
    Variable::mode          = mode;
    //Variable::remote_path   = r_path;
    //Variable::local_path    = l_path; 

    if ( mode == "p" )
    {

        Variable::remote_path   = std::string( argv[3] );
        Variable::local_path    = std::string( argv[4] );

        Logger::sys( "Connect to master" );
        MRT::Maraton::instance()->regist( make_uptr( MasterConnector , Variable::master_ip ) );
        MRT::Maraton::instance()->loop();
        auto block_num = Variable::token->address_size();

        if ( Variable::token == nullptr )
        {
            Logger::error( "Server disconnected.." );
            return 1;
        }

        Logger::sys( "Start uploading block" );

        if ( !FileStream::exist( Variable::local_path ) )
        {
            Logger::error( "Local file do not exist" );
            return 1;
        }

        if ( Variable::token == nullptr )
        {
            Logger::error( "Master has no such file" );
            return 1;
        }

        auto block_count = Variable::token->address_size();

        for ( size_t i = 0; i < block_count; i++ )
        {
            Logger::sys( "Uploading block %d/%d" , i , block_count );
            Variable::block_index = i;
            MRT::Maraton::instance()->regist( make_uptr( PutConnector , Variable::token->address( i ) ) );
            MRT::Maraton::instance()->loop();
        }
    }
    else if ( mode == "g" )
    {
        for ( size_t fn = 3; fn < argc; fn++ )
        {
            char cwd[1024] = { 0 };
            size_t cwd_size = 1024;
            uv_cwd( cwd , &cwd_size );

            std::string cur_dir = std::string( cwd , cwd_size ) + "/";

            std::string r_path      = std::string( argv[fn] );
            Path path( r_path , '/' );

            Variable::remote_path   = r_path;
            Variable::local_path    = cur_dir + path.file_name();

            Logger::sys( "Connect to master" );
            MRT::Maraton::instance()->regist( make_uptr( MasterConnector , Variable::master_ip ) );
            MRT::Maraton::instance()->loop();

            if ( Variable::token == nullptr )
            {
                Logger::error( "Server disconnected.." );
                continue;
            }

            auto block_num = Variable::token->address_size();

            Logger::sys( "Start downloading block" );

            auto block_count = Variable::token->address_size();

            Variable::file_offset = 0;
            Variable::ostream.open( Variable::local_path , std::ios::out | std::ios::binary | std::ios::trunc );

            for ( size_t i = 0; i < block_count; i++ )
            {
                Logger::sys( "Download block %d/%d" , i , block_count );
                Variable::block_index = i;
                MRT::Maraton::instance()->regist( make_uptr( GetConnector , Variable::token->address( i ) ) );
                MRT::Maraton::instance()->loop();
            }

            Variable::ostream.close();
        }
    }
    else
    {
        print_help();
        return 1;
    }

    return 0;
}