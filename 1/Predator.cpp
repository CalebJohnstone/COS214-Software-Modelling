#include "Predator.h"

//constructor
Predator::Predator(int healthPoints, string huntingMethod, int damage, string specialityAttack) : healthPoints(healthPoints), huntingMethod(huntingMethod), damage(damage), specialityAttack(specialityAttack){
    state = new PredatorState(healthPoints, huntingMethod, damage, specialityAttack);
}

//destructor
Predator::~Predator(){
    //PredatorStore takes care of de-allocating the state variable stored in the Predator class
}

//methods
int Predator::getHP() const{
    return this->healthPoints;
}

void Predator::setHP(int healthPoints){
    this->healthPoints = healthPoints;
}

string Predator::getHuntingMethod() const{
    return this->huntingMethod;
}

void Predator::setHuntingMethod(string huntingMethod){
    this->huntingMethod = huntingMethod;
}

int Predator::getDamage() const{
    return this->damage;
}

void Predator::setDamage(int damage){
    this->damage = damage;
}

string Predator::getSpeciality() const{
    return this->specialityAttack;
}

void Predator::setSpeciality(string specialityAttack){
    this->specialityAttack = specialityAttack;
}

void Predator::hunt(Prey* prey){
    //both are still alive
    while(this->healthPoints > 0 && prey->getHP() > 0){
        if(this->healthPoints < 5){
            this->speciality();
        }

        if(this->catchPrey(prey)){
            //prey caught

            if(this->getAttacked(prey)){
                //predator dies
                this->die();
            }
            else{
                this->attack(prey);
            }
        }
        else{
            //-1 HP for the predator
            this->healthPoints -= 1;
        }
    }
}

//memento pattern
void Predator::setMemento(PredatorMemento* m){
    //set the state from the given memento
    state = m->state;

    //set the attribute values to the values contained in the memento's state
    healthPoints = state->getHP();
    huntingMethod = state->getHuntingMethod();
    damage = state->getDamage();
    specialityAttack = state->getSpeciality();
}

PredatorMemento* Predator::createMemento(){
    return new PredatorMemento(healthPoints, huntingMethod, damage, specialityAttack);
}