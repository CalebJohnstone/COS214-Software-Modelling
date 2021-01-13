#include "Lion.h"

//constructor
Lion::Lion(int healthPoints, string huntingMethod, int damage, string specialityAttack) : Predator(healthPoints, huntingMethod, damage, specialityAttack){
    
}

//constructor -> needed because the provided main uses it
Lion::Lion(string huntingMethod, string specialityAttack) : Predator(13, huntingMethod, 5, specialityAttack) {
    
}

Lion::~Lion(){
    
}

//primitive operations
bool Lion::catchPrey(Prey* p){
    cout << "The lion pounces into action to catch the " << p->getType() << "." << endl;
    return p->run();
}

bool Lion::getAttacked(Prey* p){
    if(this->catchPrey(p)){
        int fightValue = p->fight();

        //fight
        if(fightValue > 0){
            //inflict damage
            cout << "The " << p->getType() << " stands on the lions tail inflicting " << p->getDamage() << " damage!" << endl;

            //subtract from predators HP (fightValue is the prey's damage if the result of Prey::fight is > 0)
            this->healthPoints -= fightValue;

            if(this->healthPoints <= 0){
                return true;
            }
        }
    }

    //predator not killed
    return false;
}

bool Lion::attack(Prey* p){
    cout << "The lion uses " << this->huntingMethod << " to inflict " << this->damage << " damage on the " << p->getType() << "." << endl;
    return (p->takeDamage(this->damage) <= 0);
}

void Lion::die(){
    cout << "Long lived the King." << endl;
}

void Lion::speciality(){
    cout << "The injured lion uses " << this->specialityAttack << "." << endl;

    //increase damage by 10%
    this->damage *= 1.1;
}

string Lion::getType(){
    return "Lion";
}