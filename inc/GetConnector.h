/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-17
* Description:
* * * * * * * * * * * * * * * */

#ifndef GET_CONNECTOR_H_
#define GET_CONNECTOR_H_

#include <string>
#include <MRT.h>

class GetConnector :
    public MRT::Connector
{
public:

    GetConnector( std::string ip );
    ~GetConnector( );

    virtual MRT::Session * create_session( ) override;

    virtual void on_session_open( MRT::Session * session ) override;

    virtual void on_session_close( MRT::Session * session ) override;

};

#endif // !GET_CONNECTOR_H_
