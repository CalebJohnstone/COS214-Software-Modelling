#include "Command.h"

Command::Command(RemoteControlVehicle* receiver) : receiver(receiver){
    
}

Command::~Command(){
    delete receiver;
}