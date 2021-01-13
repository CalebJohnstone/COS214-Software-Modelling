#ifndef Mask_H
#define Mask_H

#include <iostream>
#include <string>

#include "ImageAdditions.h"

using namespace std;

class Mask : public ImageAdditions {
public:
    //constructor and destructor
	Mask();
    ~Mask();

    void drawPoster();
};

#endif