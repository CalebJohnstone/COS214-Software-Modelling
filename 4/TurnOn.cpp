#include "TurnOn.h"

//constructor and destructor
TurnOn::TurnOn(RemoteControlVehicle* receiver) : Command(receiver){

}

TurnOn::~TurnOn(){

}

//methods
void TurnOn::execute(){
    receiver->on();
}

void TurnOn::undo(){
    receiver->off();
}