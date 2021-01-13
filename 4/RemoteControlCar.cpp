#include "RemoteControlCar.h"

//constructor and destructor
RemoteControlCar::RemoteControlCar(string name) : RemoteControlVehicle(name){

}

RemoteControlCar::~RemoteControlCar(){

}

//methods
void RemoteControlCar::on(){
    if(isOn){
        cout << "RC car is already turned on." << endl;
    }else{
        isOn = true;
        cout << "RC car is turned on." << endl;
    }
}

void RemoteControlCar::off(){
    if(!isOn){
        cout << "RC car is already turned off." << endl;
    }else{
        isOn = false;
        cout << "RC car is turned off." << endl;
    }
}

void RemoteControlCar::forward(){
    if(isOn){
        cout << "RC car drives forward quickly." << endl;
    }else{
        cout << "RC car is not on, so it cannot drive forwards right now." << endl;
    }
}
void RemoteControlCar::backward(){
    if(isOn){
        cout << "RC car reverses backward carefully." << endl;
    }else{
        cout << "RC car is not on, so it cannot drive backwards right now." << endl;
    }
}

void RemoteControlCar::handleRequest(string requestType, string apply, bool applied){
    if(requestType == "speed"){
        if(isOn){
            cout << "RC car [\"" << name << "\"] is now speeding - way above the suggested speed limit!" << endl;
            applied = true;
        }else{
            cout << "RC car [\"" << name << "\"] is not on, so it cannot speed right now." << endl;
        }

        if(apply != "all" && apply != "first"){
           RemoteControlVehicle::invalidApplyMessage(apply);
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

void RemoteControlCar::reverseRequest(string requestType, string apply, bool applied){
    if(requestType == "speed"){
        if(isOn){
            cout << "RC car [\"" << name << "\"] is no longer speeding - now staying below the speed limit!" << endl;
            applied = true;
        }else{
            cout << "RC car [\"" << name << "\"] is not on, so it cannot be stopped from speeding right now." << endl;
        }

        if(apply != "all" && apply != "first"){
           RemoteControlVehicle::invalidApplyMessage(apply);
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