#ifndef Prisoner_H
#define Prisoner_H

#include <iostream>

#include "human.h"
#include "Subject.h"

using namespace std;

class Prisoner : public Human, public Subject{
	public:
        enum Direction {up, down, left, right};

		Prisoner(int x, int y);	
        void setX(int x);
        void setY(int y);
        void runTowards(Direction direction);

        int getX();
        int getY();
};

#endif