#ifndef ImageAdditions_H
#define ImageAdditions_H

#include <iostream>
#include <string>
#include <fstream>

#include "Poster.h"

using namespace std;

//abstract decorator (Decorator Pattern)
class ImageAdditions : public Poster {
protected:
    Poster* addition;//the next decoration in the chain until we get to the ImageElement

public:
    //constructor and destructor
	ImageAdditions();
    virtual ~ImageAdditions();

    //methods
    void drawElement(Poster* element);
    virtual void drawPoster() = 0;//drawPoster the pixels of this ImageAddition
};

#endif