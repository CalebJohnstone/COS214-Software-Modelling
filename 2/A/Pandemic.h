#ifndef Pandemic_H
#define Pandemic_H

#include <iostream>
#include <string>

#include "LevelState.h"
#include "PandemicStrategy.h"

#include "levelOneStrategy.h"
#include "levelTwoStrategy.h"
#include "levelThreeStrategy.h"
#include "levelFourStrategy.h"
#include "levelFiveStrategy.h"

using namespace std;

class Pandemic {
private:
    string name;
    LevelState* state;
    PandemicStrategy* strategy;

public:
    //constructor and destructor
	Pandemic(string name);
    ~Pandemic();

    //methods
    string getName() const;

    //State pattern
    void increaseLevel();
    void decreaseLevel();

    //Strategy pattern
    void takeAction();
    void setState(LevelState* state);
};

#endif