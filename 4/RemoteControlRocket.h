#ifndef RemoteControlRocket_H
#define RemoteControlRocket_H

#include <iostream>
#include <string>
using namespace std;

class RemoteControlRocket {
public:
    //constructor and destructor
	RemoteControlRocket();
    ~RemoteControlRocket();

    //methods
    void takeOff();
    void stopLaunch();
    void increaseThrottle();
    void decreaseThrottle();
};

#endif