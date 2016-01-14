#include <PutConnector.h>
#include <PutSession.h>

PutConnector::PutConnector( std::string ip )
    : MRT::Connector( ip , 101 )
{

}

PutConnector::~PutConnector( )
{
}

MRT::Session * PutConnector::create_session( )
{
    return new PutSession( );
}

void PutConnector::on_session_open( MRT::Session * session )
{

}

void PutConnector::on_session_close( MRT::Session * session )
{

}
