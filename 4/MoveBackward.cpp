#include "MoveBackward.h"

//constructor and destructor
MoveBackward::MoveBackward(RemoteControlVehicle* receiver) : Command(receiver){

}

MoveBackward::~MoveBackward(){

}

//methods
void MoveBackward::execute(){
    receiver->backward();
}

void MoveBackward::undo(){
    receiver->forward();
}