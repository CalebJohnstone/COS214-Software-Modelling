#ifndef levelFiveStrategy_H
#define levelFiveStrategy_H

#include <iostream>
#include <string>

#include "PandemicStrategy.h"

using namespace std;

class levelFiveStrategy : public PandemicStrategy {
private:

public:
    //constructor and destructor
	levelFiveStrategy();
    ~levelFiveStrategy();

    //methods
    string takeAction();
};

#endif