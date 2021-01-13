#include "BorderGuard.h"

BorderGuard::BorderGuard(int x, int y, Prisoner* prisoner) : Human('+', x, y), mPrisoner(prisoner){

}

void BorderGuard::update(){
    //check if the prisoner is at least one of the borders being watched by this guard
    if(getX() == mPrisoner->getX() || getY() == mPrisoner->getY()){
        //blow the whistle
        cout << "The prisoner is on one of the borders. Blowing the whistle!" << endl;

        //force the prisoner back into the area (change x and y iff at same spot as guard (the guard's corner))
        if(getX() == mPrisoner->getX()){
            //change x-coordinate
            mPrisoner->setX(mPrisoner->getX() + (getX() == 0 ? 1 : -1));
        }else{
            //change y-coordinate
            mPrisoner->setY(mPrisoner->getY() + (getY() == 0 ? 1 : -1));
        }
    }
}

