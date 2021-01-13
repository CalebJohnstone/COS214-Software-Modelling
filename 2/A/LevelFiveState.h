#ifndef LevelFiveState_H
#define LevelFiveState_H

#include "LevelState.h"
#include "LevelFourState.h"

class LevelFiveState : public LevelState {
public:
    //constructor and destructor
	LevelFiveState();
    ~LevelFiveState();

    //abstract method implementations
    void handle();
    LevelState* changePandemicLevel(bool increase);
};

#endif