#ifndef LevelThreeState_H
#define LevelThreeState_H

#include "LevelState.h"
#include "LevelFourState.h"
#include "LevelTwoState.h"

class LevelThreeState : public LevelState {
public:
    //constructor and destructor
	LevelThreeState();
    ~LevelThreeState();

    //abstract method implementations
    void handle();
    LevelState* changePandemicLevel(bool increase);
};

#endif