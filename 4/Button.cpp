#include "Button.h"

//constructor and destructor
Button::Button(Command* command) : command(command){

}

Button::~Button(){
    delete command;
}

//methods
void Button::press(){
    command->execute();
}

void Button::undoPress(){
    command->undo();
}