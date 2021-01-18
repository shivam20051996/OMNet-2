/*
 * server.cc
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

Define_Module(server);

void server::initialize(){

}

void server:: handleMessage(cMessage *msg)
{
  msg = new cMessage ("CTS");
  cModule *target=getPParentModule()->getSubmoddule("client");
  sendDirect(msg,target,"radioIp");
}
