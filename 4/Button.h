#ifndef Button_H
#define Button_H

#include <iostream>
#include <string>
#include "Command.h"

using namespace std;

class Button {
private:
    Command* command;

public:
    //constructor and destructor
	Button(Command* command);
    ~Button();

    //methods
    void press();
    void undoPress();
};

#endif