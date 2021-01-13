#ifndef levelFourStrategy_H
#define levelFourStrategy_H

#include <iostream>
#include <string>

#include "PandemicStrategy.h"

using namespace std;

class levelFourStrategy : public PandemicStrategy {
private:

public:
    //constructor and destructor
	levelFourStrategy();
    ~levelFourStrategy();

    //methods
    string takeAction();
};

#endif