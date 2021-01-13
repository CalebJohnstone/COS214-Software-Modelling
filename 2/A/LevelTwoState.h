#ifndef LevelTwoState_H
#define LevelTwoState_H

#include "LevelState.h"
#include "LevelThreeState.h"
#include "LevelOneState.h"

class LevelTwoState : public LevelState {
public:
    //constructor and destructor
	LevelTwoState();
    ~LevelTwoState();

    //abstract method implementations
    void handle();
    LevelState* changePandemicLevel(bool increase);
};

#endif