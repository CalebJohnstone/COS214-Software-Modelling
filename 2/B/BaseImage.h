#ifndef BaseImage_H
#define BaseImage_H

#include <iostream>
#include <string>
#include <fstream>

#include "Poster.h"
#include "ImageElement.h"
#include "ImageAdditions.h"

#define RESET "\033[0m"

using namespace std;

class BaseImage : public Poster {
private:
    //array of Poster pointers --> determines the height of the image (each Poster pointer points to a ImageElement)
    Poster** elements;
    int numElements;
    int currentElement;

    string* colourCodeArray;

    void drawBorderLine();
    void addElement(Poster* imageElement);//the actual ImageElement
public:
    //constructor and destructor
	BaseImage(string filename);
    ~BaseImage();
    
    void addToElement(int number, ImageAdditions* addition);//decorations for the ImageElement
    
    void drawPoster();
};

#endif