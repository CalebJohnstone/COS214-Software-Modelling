#ifndef TemperatureCheck_H
#define TemperatureCheck_H

#include <iostream>
#include <string>

#include "ImageAdditions.h"

using namespace std;

class TemperatureCheck : public ImageAdditions {
public:
    //constructor and destructor
	TemperatureCheck();
    ~TemperatureCheck();

    void drawPoster();
};

#endif