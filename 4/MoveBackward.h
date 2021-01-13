#ifndef MoveBackward_H
#define MoveBackward_H

#include <iostream>
#include <string>
#include "Command.h"

using namespace std;

class MoveBackward : public Command {
public:
    //constructor and destructor
	MoveBackward(RemoteControlVehicle* receiver);
    ~MoveBackward();

    //methods
    void execute();
    void undo();
};

#endif