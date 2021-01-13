#include "MoveForward.h"

//constructor and destructor
MoveForward::MoveForward(RemoteControlVehicle* receiver) : Command(receiver){

}

MoveForward::~MoveForward(){
    
}

//methods
void MoveForward::execute(){
    receiver->forward();
}

void MoveForward::undo(){
    receiver->backward();
}