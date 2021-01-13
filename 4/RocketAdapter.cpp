#include "RocketAdapter.h"

//constructor and destructor
RocketAdapter::RocketAdapter(RemoteControlRocket* adaptee) : RemoteControlVehicle("rocket adapter"), adaptee(adaptee){

}

RocketAdapter::~RocketAdapter(){

}

//methods
void RocketAdapter::on(){
    if(isOn){
        cout << "RC rocket is already turned on." << endl;
    }else{
        //turn on
        isOn = true;

        adaptee->takeOff();
    }
}

void RocketAdapter::off(){
    if(!isOn){
        cout << "RC rocket is already turned off." << endl;
    }else{
        //turn off
        isOn = false;

        adaptee->stopLaunch();
    }
}

void RocketAdapter::forward(){
    if(isOn){
        adaptee->increaseThrottle();
    }else{
        cout << "RC rocket is not on, so it cannot be moved forwards (a.k.a. increase its throttle) right now." << endl;
    }
}

void RocketAdapter::backward(){
    if(isOn){
        adaptee->decreaseThrottle();
    }else{
        cout << "RC rocket is not on, so it cannot be moved backwards (a.k.a. decrease its throttle) right now." << endl;
    }
}

void RocketAdapter::handleRequest(string requestType, string apply, bool applied){
    //can't deal with any requests (not responsible for any type of request)
    if(next){
        next->handleRequest(requestType, apply, applied);
    }else if(!applied){
        RemoteControlVehicle::requestErrorMesssage(requestType);
    }
}

void RocketAdapter::reverseRequest(string requestType, string apply, bool applied){
    //can't deal with any requests (not responsible for any type of request)
    if(next){
        next->reverseRequest(requestType, apply, applied);
    }else if(!applied){
        RemoteControlVehicle::requestErrorMesssage(requestType);
    }
}