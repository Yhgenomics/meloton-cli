#include "MRT.h"
#include <string>

int main( int argc , char* argv[] )
{
    if ( argc != 3 )
    {
        return 0;
    }
    
    std::string mode = std::string( argv[0] );
    std::string r_path = std::string( argv[1] );
    std::string l_path = std::string( argv[2] );



    return 0;
}