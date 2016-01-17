#include <GetConnector.h>
#include <GetSession.h>

GetConnector::GetConnector( std::string ip )
    : Connector( ip , 101 )
{

}

GetConnector::~GetConnector( )
{

}

MRT::Session * GetConnector::create_session( )
{
    return new GetSession( );
}

void GetConnector::on_session_open( MRT::Session * session )
{

}

void GetConnector::on_session_close( MRT::Session * session )
{

}
