#include "TurnOff.h"

//constructor and destructor
TurnOff::TurnOff(RemoteControlVehicle* receiver) : Command(receiver){

}

TurnOff::~TurnOff(){

}

//methods
void TurnOff::execute(){
    receiver->off();
}

void TurnOff::undo(){
    receiver->on();
}