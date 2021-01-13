#include "PredatorMemento.h"

PredatorMemento::PredatorMemento(int HP, string huntingMethod, int damage, string specialityAttack){
    state = new PredatorState(HP, huntingMethod, damage, specialityAttack);
}

PredatorMemento::~PredatorMemento(){
    delete state;
    state = nullptr;
}

PredatorState* PredatorMemento::getState() const{
    return state;
}