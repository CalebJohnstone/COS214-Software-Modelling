#ifndef NoLevelState_H
#define NoLevelState_H

#include "LevelState.h"
#include "LevelOneState.h"

class NoLevelState : public LevelState {
public:
    //constructor and destructor
	NoLevelState();
    ~NoLevelState();

    //abstract method implementations
    void handle();
    LevelState* changePandemicLevel(bool increase);
};

#endif