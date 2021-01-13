#ifndef Poster_H
#define Poster_H

#include <iostream>
#include <string>
using namespace std;

//abstract component class (Composite and Decorator Patterns)
class Poster {
private:
    string name;
public:
    //constructor and destructor
	Poster();
    virtual ~Poster();

    //methods
    virtual void drawPoster() = 0;//the "base function"
};

#endif