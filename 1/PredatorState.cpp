#include  "PredatorState.h"

PredatorState::PredatorState(int HP, string huntingMethod, int damage, string specialityAttack) : healthPoints(HP), huntingMethod(huntingMethod), damage(damage), specialityAttack(specialityAttack){

}

PredatorState::~PredatorState(){}
    
int PredatorState::getHP() const{
    return healthPoints;
}

string PredatorState::getHuntingMethod() const{
    return huntingMethod;
}

int PredatorState::getDamage() const{
    return damage;
}

string PredatorState::getSpeciality() const{
    return specialityAttack;
}