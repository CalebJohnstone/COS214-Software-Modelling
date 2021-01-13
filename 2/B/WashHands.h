#ifndef WashHands_H
#define WashHands_H

#include <iostream>
#include <string>

#include "ImageAdditions.h"

using namespace std;

class WashHands : public ImageAdditions {
public:
    //constructor and destructor
	WashHands();
    ~WashHands();

    void drawPoster();
};

#endif