#ifndef BorderGuard_H
#define BorderGuard_H

#include <iostream>

#include "Prisoner.h"
#include "Observer.h"
#include "human.h"

using namespace std;

class BorderGuard : public Observer, public Human {
	public:
		BorderGuard(int x, int y, Prisoner* prisoner);
        void update();
        
    private:
        Prisoner* mPrisoner;
};

#endif