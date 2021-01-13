#ifndef LevelFourState_H
#define LevelFourState_H

#include "LevelState.h"
#include "LevelFiveState.h"
#include "LevelThreeState.h"

class LevelFourState : public LevelState {
public:
    //constructor and destructor
	LevelFourState();
    ~LevelFourState();

    //abstract method implementations
    void handle();
    LevelState* changePandemicLevel(bool increase);
};

#endif