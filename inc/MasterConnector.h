/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-14
* Description:
* * * * * * * * * * * * * * * */

#ifndef MASTER_CONNECTOR_H_
#define MASTER_CONNECTOR_H_

#include <MRT.h>

class MasterConnector :
    public MRT::Connector
{
public:
    
    MasterConnector( std::string ip );
    ~MasterConnector( );

    virtual MRT::Session * create_session( ) override;
    virtual void on_session_open( MRT::Session * session ) override;
    virtual void on_session_close( MRT::Session * session ) override;

};

#endif // !MASTER_CONNECTOR_H_
