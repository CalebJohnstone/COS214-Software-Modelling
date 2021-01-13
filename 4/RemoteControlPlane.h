#ifndef RemoteControlPlane_H
#define RemoteControlPlane_H

#include <iostream>
#include <string>
#include "RemoteControlVehicle.h"

using namespace std;

class RemoteControlPlane : public RemoteControlVehicle {
public:
    //constructor and destructor
	RemoteControlPlane(string name);
    virtual ~RemoteControlPlane();

    //methods
    void on();
    void off();
    void forward();
    void backward();

    void handleRequest(string requestType, string apply, bool applied);
    void reverseRequest(string requestType, string apply, bool applied);
};

#endif