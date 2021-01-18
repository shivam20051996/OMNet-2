/*
 * client.cc
 *
 *  Created on: 18-Jan-2021
 *      Author: patid
 */

#include<omnetpp.h>

class server : public cSimpleModule {

    cMessage *msg;
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

};

Define_Module(client);

void client::initialize() {
    cout<<"client initialize"<<endl;
    msg=new cMessage("RTS");
    scheduleAt(simTime() + dblrand(),msg->dup() );
    cout<<"Client initialize complete"<<endl;
}

void client::handleMessage(cMessage *msg)
{
  cout<<"client handle message initialize"<<endl;
  cModule *target;
  mag=new cMessage("RTS");
  target = getPatentModule()->getModule("server");
  sendDirect(msg,target,"radioIn");
  scheduleAt(simTime() + dblrand(),msg->dup() );
}


