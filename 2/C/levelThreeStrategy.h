#ifndef levelThreeStrategy_H
#define levelThreeStrategy_H

#include <iostream>
#include <string>

#include "PandemicStrategy.h"

using namespace std;

class levelThreeStrategy : public PandemicStrategy {
private:

public:
    //constructor and destructor
	levelThreeStrategy();
    ~levelThreeStrategy();

    //methods
    string takeAction();
};

#endif