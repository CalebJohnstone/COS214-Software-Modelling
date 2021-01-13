#ifndef LevelOneState_H
#define LevelOneState_H

#include "LevelState.h"
#include "LevelTwoState.h"
#include "NoLevelState.h"

class LevelOneState : public LevelState {
public:
    //constructor and destructor
	LevelOneState();
    ~LevelOneState();

    //abstract method implementations
    void handle();
    LevelState* changePandemicLevel(bool increase);
};

#endif