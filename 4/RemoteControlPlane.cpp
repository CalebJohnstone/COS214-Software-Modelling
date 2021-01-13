#include "RemoteControlPlane.h"

//constructor and destructor
RemoteControlPlane::RemoteControlPlane(string name) : RemoteControlVehicle(name){

}

RemoteControlPlane::~RemoteControlPlane(){

}

//methods
void RemoteControlPlane::on(){
    if(isOn){
        cout << "RC plane is already turned on." << endl;
    }else{
        isOn = true;
        cout << "RC plane is turned on." << endl;
    }
}

void RemoteControlPlane::off(){
    if(!isOn){
        cout << "RC plane is already turned off." << endl;
    }else{
        isOn = false;
        cout << "RC plane is turned off." << endl;
    }
}

void RemoteControlPlane::forward(){
    if(isOn){
        cout << "RC plane pulls up into a vertical climb." << endl;
    }else{
        cout << "RC plane is not on, so it cannot pull up into a vertical climb right now." << endl;
    }
}
void RemoteControlPlane::backward(){
    if(isOn){
        cout << "RC plane points its nose down into a dive." << endl;
    }else{
        cout << "RC plane is not on, so it cannot point its nose down into a dive right now." << endl;
    }
}

void RemoteControlPlane::handleRequest(string requestType, string apply, bool applied){
    if(requestType == "fly"){
        if(isOn){
            cout << "RC plane [\"" << name << "\"] is now flying!" << endl;
            applied = true;
        }else{
            cout << "RC plane [\"" << name << "\"] is not on, so it cannot fly right now." << endl;
        }

        if(apply != "all" && apply != "first"){
           RemoteControlVehicle::invalidApplyMessage(apply);
           return;
        }else if(apply == "first" && isOn){
            return;//stop once handled by the first vehicle that can handle the request
        }
    }
    
    if(next){
        next->handleRequest(requestType, apply, applied);
    }else if(!applied){
        RemoteControlVehicle::requestErrorMesssage(requestType);
    }
}

void RemoteControlPlane::reverseRequest(string requestType, string apply, bool applied){
    if(requestType == "fly"){
        if(isOn){
            cout << "RC plane [\"" << name << "\"] is no longer flying!" << endl;
            applied = true;
        }else{
            cout << "RC plane [\"" << name << "\"] is not on, so it cannot be stopped from flying right now." << endl;
        }

        if(apply != "all" && apply != "first"){
           RemoteControlVehicle::invalidApplyMessage(apply);
           return;
        }else if(apply == "first" && isOn){
            return;//stop once handled by the first vehicle that can handle the request
        }
    }
    
    if(next){
        next->reverseRequest(requestType, apply, applied);
    }else if(!applied){
        RemoteControlVehicle::requestErrorMesssage(requestType);
    }
}