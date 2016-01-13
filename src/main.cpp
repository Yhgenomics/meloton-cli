#include "MRT.h"
#include <string>

void print_help( )
{
    fprintf( stdout , "YHFS" );
    fprintf( stdout , "YHGenomics inc." );
    fprintf( stdout , "========================================" );
    fprintf( stdout , "usage" );
    fprintf( stdout , "meloton-cli <mode> <remote file> <local file> \r\n" );
    fprintf( stdout , "mode \r\n" );
    fprintf( stdout , "     get : download <remote file> to <local file> \r\n" );
    fprintf( stdout , "     put : upload <local file> to <remote file> \r\n" );
}

int main( int argc , char* argv[] )
{
    if ( argc != 4 )
    {
        print_help( );
        return 1;
    }
    
    std::string mode = std::string( argv[0] );
    std::string r_path = std::string( argv[1] );
    std::string l_path = std::string( argv[2] );

    if ( mode == "p" )
    {

    }
    else if ( mode == "g" )
    {

    }
    else
    {
        print_help( );
        return 1;
    }

    return 0;
}