#ifndef levelOneStrategy_H
#define levelOneStrategy_H

#include <iostream>
#include <string>

#include "PandemicStrategy.h"

using namespace std;

class levelOneStrategy : public PandemicStrategy {
private:

public:
    //constructor and destructor
	levelOneStrategy();
    ~levelOneStrategy();

    //methods
    string takeAction();
};

#endif