#ifndef Pandemic_H
#define Pandemic_H

#include <iostream>
#include <string>
#include <sstream>

#include "LevelState.h"
#include "PandemicStrategy.h"

#include "levelOneStrategy.h"
#include "levelTwoStrategy.h"
#include "levelThreeStrategy.h"
#include "levelFourStrategy.h"
#include "levelFiveStrategy.h"

#include "BaseImage.h"
#include "Mask.h"
#include "WashHands.h"
#include "UseHandSanitiser.h"
#include "TemperatureCheck.h"

using namespace std;

class Pandemic {
private:
    string name;
    LevelState* state;
    PandemicStrategy* strategy;

    //SECTION C
    BaseImage* poster = nullptr;

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

    //SECTION C
    void setPoster();
};

#endif