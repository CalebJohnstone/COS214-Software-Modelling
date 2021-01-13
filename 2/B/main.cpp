#include <iostream>
#include <string>

#include "Poster.h"
#include "Mask.h"
#include "TemperatureCheck.h"
#include "UseHandSanitiser.h"
#include "WashHands.h"

#include "BaseImage.h"

using namespace std;

int main() {
	//create the image of the poster with n ImageElements
	BaseImage* poster = new BaseImage("posterA_elements.txt");

	//add ImageAdditions that decorate the ImageElement
	poster->addToElement(1, new Mask());
	poster->addToElement(1, new TemperatureCheck());//Mask::drawElement() called
	poster->addToElement(1, new UseHandSanitiser());//Temperature::drawElement() called
	poster->addToElement(1, new WashHands());//UseHandSanitiser::drawElement() called

	//draw the poster
	cout << endl;
	cout << "Drawing Poster A" << endl;
	poster->drawPoster();
	
	//Memory-free
	delete poster;
	poster = nullptr;

	return 0;
}