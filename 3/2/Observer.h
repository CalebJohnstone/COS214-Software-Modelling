#ifndef Observer_H
#define Observer_H

#include <iostream>

using namespace std;

class Observer{
	public:
		Observer();
        virtual void update() = 0;
};

#endif