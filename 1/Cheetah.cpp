#include "Cheetah.h"

//constructor
Cheetah::Cheetah(int healthPoints, string huntingMethod, int damage, string specialityAttack) : Predator(healthPoints, huntingMethod, damage, specialityAttack){
    
}

//constructor -> needed because the provided main uses it
Cheetah::Cheetah(string huntingMethod, string specialityAttack) : Predator(11, huntingMethod, 4, specialityAttack) {
    
}

Cheetah::~Cheetah(){

}

//primitive operations
bool Cheetah::catchPrey(Prey* p){
    cout << "The cheetah sprints forward with its eye on the " << p->getType() << "." << endl;
    return p->run();
}

bool Cheetah::getAttacked(Prey* p){
    if(this->catchPrey(p)){
        int fightValue = p->fight();

        //fight
        if(fightValue > 0){
            //inflict damage
            cout << "The " << p->getType() << " side steps the cheetah, kicks back and causes " << p->getDamage() << " damage in the process." << endl;

            //subtract from predators HP (fightValue is the prey's damage if the result of Prey::fight() is > 0)
            this->healthPoints -= fightValue;

            if(this->healthPoints <= 0){
                return true;
            }
        }
    }

    //predator not killed
    return false;
}

bool Cheetah::attack(Prey* p){
    cout << "The cheetah causes " << this->damage << " damage to the " << p->getType() << " by using " << this->huntingMethod << "." << endl;
    return (p->takeDamage(this->damage) <= 0);
}

void Cheetah::die(){
    cout << "The hunter becomes the hunted." << endl;
}

void Cheetah::speciality(){
    cout << "The tired cheetah uses " << this->specialityAttack << "." << endl;

    //increase damage by 10%
    this->damage *= 1.1;
}

string Cheetah::getType(){
    return "Cheetah";
}