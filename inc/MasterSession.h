/* * * * * * * * * * * * * * * *
* YHGenomics Inc.
* Author     : yang shubo
* Date       : 2016-01-16
* Description:
* * * * * * * * * * * * * * * */

#ifndef MASTER_SESSION_H_
#define MASTER_SESSION_H_

#include <MRT.h>
#include <ProtocolSession.h>

class MasterSession :
    public ProtocolSession
{
public:
    virtual void on_connect ( ) override;
};

#endif // !MASTER_SESSION_H_
