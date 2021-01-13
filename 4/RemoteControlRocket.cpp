#include "RemoteControlRocket.h"

//constructor and destructor
RemoteControlRocket::RemoteControlRocket(){

}

RemoteControlRocket::~RemoteControlRocket(){

}

//methods
void RemoteControlRocket::takeOff(){
    cout << "The RC rocket blasts off its take-off platform." << endl;
}

void RemoteControlRocket::stopLaunch(){
    cout << "The RC rocket deploys its parachute and floats down to the ground." << endl;
}

void RemoteControlRocket::increaseThrottle(){
    cout << "The RC rocket increases its throttle and accelerates." << endl;
}

void RemoteControlRocket::decreaseThrottle(){
    cout << "The RC rocket decreases its throttle and ascends at a slower rate." << endl;
}