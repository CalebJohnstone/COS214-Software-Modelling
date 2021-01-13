#ifndef RemoteControlVehicle_H
#define RemoteControlVehicle_H

#include <iostream>
#include <string>
using namespace std;

class RemoteControlVehicle {
protected:
    string name;
    bool isOn;
    RemoteControlVehicle* next;
    void requestErrorMesssage(string requestType);
    void invalidApplyMessage(string apply);

public:
    //constructor and destructor
	RemoteControlVehicle(string name);
    virtual ~RemoteControlVehicle();

    //methods
    virtual void on() = 0;
    virtual void off() = 0;
    virtual void forward() = 0;
    virtual void backward() = 0;

    //Chain of Responsibility pattern
    virtual void handleRequest(string requestType, string apply, bool applied) = 0;
    virtual void reverseRequest(string requestType, string apply, bool applied) = 0;
    void add(RemoteControlVehicle* next);
};

#endif