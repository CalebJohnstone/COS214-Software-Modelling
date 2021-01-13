#ifndef Command_H
#define Command_H

#include <iostream>
#include <string>
#include <fstream>
#include "RemoteControlVehicle.h"

using namespace std;

class Command {
protected:
    RemoteControlVehicle* receiver;

public:
    //constructor and destructor
	Command(RemoteControlVehicle* receiver);
    virtual ~Command();

    //methods
    virtual void execute() = 0;
    virtual void undo() = 0;
};

#endif