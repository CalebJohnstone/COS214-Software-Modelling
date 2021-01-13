#include "BaseImage.h"

//constructor and destructor
BaseImage::BaseImage(string filename){
    //read the basic layout of each ImageElement from the textfile

    /*textfile format:

    Line 1: number of ImageElements
    *<colour>,height#width
    <ImageElement pixels (text and border)>
    *<colour>,height#width
    <ImageElement pixels (text and border)>
    .
    .
    .

    */

   ifstream file(filename);
   string line;

   if(file.is_open()){
       //get the number of ImageElements
       getline(file, line);
       this->numElements = stoi(line);

       this->elements = new Poster*[this->numElements];

       for(int i = 0; i < this->numElements; i++){
           this->elements[i] = nullptr;
       }

       this->currentElement = 0;

       //intialise the colourCodeArray
       this->colourCodeArray = new string[this->numElements];

       int n = 3;
       string colours[n] = {"red", "green", "blue"};
       string colourCodes[n]  = {"\033[31m", "\033[32m", "\033[34m"};

       string colour;
       string colourCode;

       int height;
       int width;

       char** pixels = nullptr;

       int currentRow;

       while(getline(file, line)){
           //check if this line is a colour line
           if(line[0] == '*'){
               //get the colour
               colour = line.substr(1, line.find(",")-1);

               //default to white (incase the colour is invalid)
               colourCode = "";

               //find the colour in the array of colour names
               int i = 0;
               for(; i < n; i++){
                   if(colours[i] == colour){
                       colourCode = colourCodes[i];
                       break;
                   }
               }

               //clear the pixels 2D array
               if(pixels){
                   for(int i = 0; i < height; i++){
                       delete[] pixels[i];
                   }

                   delete[] pixels;
               }

                //get the height
                height = stoi(line.substr(line.find(",")+1, line.find("#")-line.find(",")));

                //get the width
                width = stoi(line.substr(line.find("#")+1));

                pixels = new char*[height];

                for(int i = 0; i < height; i++){
                    pixels[i] = new char[width];
                }

                //set the currentRow to 0
               currentRow = 0;
           }else{//pixels line
                //line contains the current row of pixels
                for(int j = 0; j < width; j++){
                    pixels[currentRow][j] = line[j];
                }

                currentRow++;

                //test if this is the last row so that we can create the ImageElement and add it to Poster** elements
                if(currentRow == height){
                    //set the colourCode
                    colourCodeArray[currentElement] = colourCode;

                    //add the element
                    this->addElement(new ImageElement(pixels, height, width));
                }
           }
       }

       file.close();
   }
   else{
       cout << "Unable to open the textfile called: " << filename << endl;
   }
}

BaseImage::~BaseImage(){
    for(int i = 0; i < this->numElements; i++){
        if(this->elements[i]){
            delete this->elements[i];
        }
    }

    delete[] this->elements;
    this->elements = nullptr;
}

void BaseImage::addElement(Poster* imageElement){
    //add the actual ImageElement
    this->elements[this->currentElement++] = imageElement;
}

void BaseImage::addToElement(int number, ImageAdditions* addition){
    //push this to the front of the list for the specified ImageElement
    if(number > 0 && number <= this->numElements){//valid number
        addition->drawElement(this->elements[number-1]);
        this->elements[number-1] = addition;
    }
    else{
        cout << "Invalid use of BaseImage::addToElement(int number, Poster* addition): number must be positive and at most the number of elements" << endl;
    }
}

//methods
void BaseImage::drawPoster(){
    //output the top border of the poster
    this->drawBorderLine();

    //for each line output *<content>*
    for(int i = 0; i < this->numElements; i++){
        cout << this->colourCodeArray[i];
        this->elements[i]->drawPoster();
        cout << RESET;
    }

    //output the bottom border of the poster
    this->drawBorderLine();
}

void BaseImage::drawBorderLine(){
    for(int i = 0; i < 80; i++){
        cout << "*";
    }

    cout << endl;
}