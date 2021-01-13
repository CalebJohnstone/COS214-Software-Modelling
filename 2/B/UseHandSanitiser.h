#ifndef UseHandSanitiser_H
#define UseHandSanitiser_H

#include <iostream>
#include <string>

#include "ImageAdditions.h"

using namespace std;

class UseHandSanitiser : public ImageAdditions {
public:
    //constructor and destructor
	UseHandSanitiser();
    ~UseHandSanitiser();

    void drawPoster();
};

#endif