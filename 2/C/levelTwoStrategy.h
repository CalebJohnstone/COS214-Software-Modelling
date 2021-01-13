#ifndef levelTwoStrategy_H
#define levelTwoStrategy_H

#include <iostream>
#include <string>

#include "PandemicStrategy.h"

using namespace std;

class levelTwoStrategy : public PandemicStrategy {
private:

public:
    //constructor and destructor
	levelTwoStrategy();
    ~levelTwoStrategy();

    //methods
    string takeAction();
};

#endif