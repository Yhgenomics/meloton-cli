#include "MRT.h"
#include <string>
#include <MasterConnector.h>
#include <PutConnector.h>
#include <GetConnector.h>
#include <Variable.h>
#include <FileStream.h>

void print_help( )
{
    fprintf( stdout , "YHFS\r\n" );
    fprintf( stdout , "Build %s\r\n" , __DATE__ );
    fprintf( stdout , "YHGenomics inc. Copyright\r\n" );
    fprintf( stdout , "========================================\r\n" );
    fprintf( stdout , "usage\r\n" );
    fprintf( stdout , "meloton-cli <mode> <master address> <remote file> <local file> \r\n" );
    fprintf( stdout , "mode \r\n" );
    fprintf( stdout , "     get : download <remote file> to <local file> \r\n" );
    fprintf( stdout , "     put : upload <local file> to <remote file> \r\n" );
    fprintf( stdout , "master address \r\n" );
    fprintf( stdout , "     master server ip address \r\n" );
}

int main( int argc , char* argv[] )
{
    if ( argc != 5 )
    {
        print_help( );
        return 1;
    }
    for ( size_t i = 0; i < 5; i++ )
    {
        printf( "argv[%lld]: %s\r\n" , i , argv[i]  );
    }
    
    std::string mode = std::string( argv[1] );
    std::string srv_addr = std::string( argv[2] );
    std::string r_path = std::string( argv[3] );
    std::string l_path = std::string( argv[4] );

    Variable::master_ip = srv_addr;
    Variable::mode = mode;
    Variable::local_path = l_path;
    Variable::remote_path = r_path;

    Logger::sys( "connect to master" );
    MRT::Maraton::instance( )->regist( make_uptr( MasterConnector , Variable::master_ip ) );
    MRT::Maraton::instance( )->loop( );

    if ( mode == "p" )
    {
        Logger::sys( "start uploading block" );

        if ( !FileStream::exist( Variable::local_path  ) )
        {
            printf( "local file do not exist\r\n" );
            return 1;
        }

        if ( Variable::token == nullptr )
        {
            printf( "master has no such file" );
            return 1;
        }

        auto block_count = Variable::token->address_size( );
         
        for ( size_t i = 0; i < block_count; i++ )
        {
            printf( "upload block %d/%d\r\n" , i , block_count);
            Variable::block_index = i;
            MRT::Maraton::instance( )->regist( make_uptr( PutConnector , Variable::token->address( i ) ) );
            MRT::Maraton::instance( )->loop( );
        }
    } 
    else if ( mode == "g" )
    { 
        Logger::sys( "start downloading block" );

        auto block_count = Variable::token->address_size( );
         
        Variable::file_stream.open( Variable::local_path , "wb+" );

        for ( size_t i = 0; i < block_count; i++ )
        {
            printf( "download block %d/%d\r\n" , i , block_count);
            Variable::block_index = i;
            MRT::Maraton::instance( )->regist( make_uptr( GetConnector , Variable::token->address( i ) ) );
            MRT::Maraton::instance( )->loop( );
        }
    }
    else
    {
        print_help( );
        return 1;
    }

    return 0;
}