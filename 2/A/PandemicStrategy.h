#ifndef PandemicStrategy_H
#define PandemicStrategy_H

#include <iostream>
#include <string>

#include "LevelState.h"

using namespace std;

class PandemicStrategy {
public:
    //constructor and destructor
	PandemicStrategy();
    ~PandemicStrategy();

    //methods
    virtual string takeAction() = 0;
};

#endif