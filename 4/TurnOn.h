#ifndef TurnOn_H
#define TurnOn_H

#include <iostream>
#include <string>
#include "Command.h"

using namespace std;

class TurnOn : public Command {
public:
    //constructor and destructor
	TurnOn(RemoteControlVehicle* receiver);
    ~TurnOn();

    //methods
    void execute();
    void undo();
};

#endif