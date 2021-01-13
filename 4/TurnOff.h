#ifndef TurnOff_H
#define TurnOff_H

#include <iostream>
#include <string>
#include "Command.h"

using namespace std;

class TurnOff : public Command {
public:
    //constructor and destructor
	TurnOff(RemoteControlVehicle* receiver);
    ~TurnOff();

    //methods
    void execute();
    void undo();
};

#endif