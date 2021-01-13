#ifndef Speed_H
#define Speed_H

#include <iostream>
#include <string>
#include "Command.h"

using namespace std;

class Speed : public Command {
private:
    string getApply();
public:
    //constructor and destructor
	Speed(RemoteControlVehicle* receiver);
    ~Speed();

    //methods
    void execute();
    void undo();
};

#endif