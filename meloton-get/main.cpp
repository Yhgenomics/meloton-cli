#include <string>

#include "Socket.hpp"

using namespace std;

string ip;
string remove_path;
string local_path;


int main( int argc , char* argv[] )
{
    if ( argc < 3 )
    {
        cout << "Usage: meloton-get <ip> <remote path> <local path>" << endl;
        return 1;
    }

    ip           = std::string( argv[0] );
    remove_path  = std::string( argv[1] );
    local_path   = std::string( argv[2] );
    
    try
    {
        Socket::TCP tcp;
        tcp.connect_to( Socket::Address( ip.c_str( ) , 100 ) );

    }
    catch(exception & exp)
    {
        cout << exp.what() << endl;
        return 1;
    }
     
    return 0;
}