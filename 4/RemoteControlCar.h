#ifndef RemoteControlCar_H
#define RemoteControlCar_H

#include <iostream>
#include <string>
#include "RemoteControlVehicle.h"

using namespace std;

class RemoteControlCar : public RemoteControlVehicle {
public:
    //constructor and destructor
	RemoteControlCar(string name);
    ~RemoteControlCar();

    //methods
    void on();
    void off();
    void forward();
    void backward();

    void handleRequest(string requestType, string apply, bool applied);
    void reverseRequest(string requestType, string apply, bool applied);
};

#endif