#ifndef ImageElement_H
#define ImageElement_H

#include <iostream>
#include <string>

#include "Poster.h"

using namespace std;

//Leaf class (Composite Pattern)
class ImageElement : public Poster {
private:
    //2d array of pixels (block)
    char** pixels;
    int height;
    int width;

public:
    //constructor and destructor
	ImageElement(char** pixelCharacters, int height, int width);
    ~ImageElement();

    void drawPoster();
};

#endif