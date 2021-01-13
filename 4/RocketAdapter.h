#ifndef RocketAdapter_H
#define RocketAdapter_H

#include <iostream>
#include <string>
#include "RemoteControlRocket.h"
#include "RemoteControlVehicle.h"

using namespace std;

class RocketAdapter : public RemoteControlVehicle {
private:
    RemoteControlRocket* adaptee;

public:
    //constructor and destructor
	RocketAdapter(RemoteControlRocket* adaptee);
    ~RocketAdapter();

    //methods
    void on();
    void off();
    void forward();
    void backward();

    void handleRequest(string requestType, string apply, bool applied);
    void reverseRequest(string requestType, string apply, bool applied);
};

#endif