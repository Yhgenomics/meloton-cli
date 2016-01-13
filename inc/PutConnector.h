/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-13
* Description:
* * * * * * * * * * * * * * * */

#ifndef PUT_CONNECTOR_H_
#define PUT_CONNECTOR_H_

#include <MRT.h>

class PutConnector :
    public MRT::Connector
{
public:

    virtual MRT::Session * create_session( ) override;

    virtual void on_session_open( MRT::Session * session ) override;

    virtual void on_session_close( MRT::Session * session ) override;

};

#endif // !PUT_CONNECTOR_H_
