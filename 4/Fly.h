#ifndef Fly_H
#define Fly_H

#include <iostream>
#include <string>
#include "Command.h"

using namespace std;

class Fly : public Command {
private:
    string getApply();
public:
    //constructor and destructor
	Fly(RemoteControlVehicle* receiver);
    ~Fly();

    //methods
    void execute();
    void undo();
};

#endif