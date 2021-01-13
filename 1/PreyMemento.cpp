#include "PreyMemento.h"

PreyMemento::PreyMemento(int HP, string type, int damage){
    state = new PreyState(HP, type, damage);
}

PreyMemento::~PreyMemento(){
    delete state;
    state = nullptr;
}

PreyState* PreyMemento::getState() const{
    return state;
}