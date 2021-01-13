#include "RemoteControlVehicle.h"

RemoteControlVehicle::RemoteControlVehicle(string name) : isOn(false), next(nullptr), name(name){

}

RemoteControlVehicle::~RemoteControlVehicle(){

}

void RemoteControlVehicle::requestErrorMesssage(string requestType){
    cout << "There was no remote control vehicle to handle the request of type: " << requestType << endl;
}

void RemoteControlVehicle::invalidApplyMessage(string apply){
    cout << "Invalid value for apply parameter: \"" << apply << "\". It must either be \"all\" or \"first\"" << endl;
}

void RemoteControlVehicle::add(RemoteControlVehicle* next){
    if(this->next){
        this->next->add(next);
    }else{
        this->next = next;
    }
}