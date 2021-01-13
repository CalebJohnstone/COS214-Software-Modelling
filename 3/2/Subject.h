#ifndef Subject_H
#define Subject_H

#include <iostream>
#include <vector>

#include "Observer.h"

using namespace std;

class Subject{
public:
	Subject();	
        void attach(Observer* observer);
        void notify();
private:
        vector<Observer*> mObservers;
};

#endif