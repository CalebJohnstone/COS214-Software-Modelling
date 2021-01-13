#include "Prisoner.h"

Prisoner::Prisoner(int x, int y) : Human('X', x, y){

}

void Prisoner::setX(int x){
    Human::setX(x);
    Subject::notify();
}

void Prisoner::setY(int y){
    Human::setY(y);
    Subject::notify();
}

void Prisoner::runTowards(Direction direction){
    //move one block in the specified direction
    switch (direction){
        case up:
            Prisoner::setY(Human::getY()-1);
            break;
        
        case down:
            Prisoner::setY(Human::getY()+1);
            break;
        
        case left:
            Prisoner::setX(Human::getX()-1);
            break;
        
        case right:
            Prisoner::setX(Human::getX()+1);
            break;
    }
}

int Prisoner::getX(){
    return Human::getX();
}

int Prisoner::getY(){
    return Human::getY();
}