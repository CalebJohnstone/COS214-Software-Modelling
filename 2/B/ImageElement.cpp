#include "ImageElement.h"

//constructor and destructor
ImageElement::ImageElement(char** pixelCharacters, int height, int width){
    this->height = height;
    this->width = width;

    this->pixels = new char*[this->height];

    for(int i = 0; i < this->height; i++){
        this->pixels[i] = new char[this->width];

        for(int j = 0; j < this->width; j++){
            this->pixels[i][j] = pixelCharacters[i][j];
        }
    }
}

ImageElement::~ImageElement(){
    for(int i = 0; i < this->height; i++){
        delete[] this->pixels[i];
    }

    delete[] this->pixels;
    this->pixels = nullptr;
}

void ImageElement::drawPoster(){
    for(int i = 0; i < this->height; i++){
        for(int j = 0; j < this->width; j++){
            cout << this->pixels[i][j];
        }

        cout << endl;
    }

    cout << endl;
}