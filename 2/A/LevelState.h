#ifndef LevelState_H
#define LevelState_H

#include <iostream>
#include <string>
using namespace std;

class LevelState {
private:
    string pandemicLevel;

public:
    //constructor and destructor
	LevelState(string pandemicLevel);
    virtual ~LevelState();

    //methods
    string getPandemicState() const;

    //abstract methods
    virtual void handle() = 0;
    virtual LevelState* changePandemicLevel(bool change) = 0;
};

#endif