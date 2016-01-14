#include <MasterConnector.h>
#include <MasterSession.h>

MasterConnector::MasterConnector( std::string ip )
    : Connector( ip , 101 )
{

}

MasterConnector::~MasterConnector( )
{

}

MRT::Session * MasterConnector::create_session( )
{
    return new MasterSession( );
}

void MasterConnector::on_session_open( MRT::Session * session )
{

}

void MasterConnector::on_session_close( MRT::Session * session )
{

}
