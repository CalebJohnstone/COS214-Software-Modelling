#ifndef MoveForward_H
#define MoveForward_H

#include <iostream>
#include <string>
#include "Command.h"

using namespace std;

class MoveForward : public Command {
public:
    //constructor and destructor
	MoveForward(RemoteControlVehicle* receiver);
    ~MoveForward();

    //methods
    void execute();
    void undo();
};

#endif