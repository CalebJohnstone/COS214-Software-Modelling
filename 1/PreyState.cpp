#include "PreyState.h"

PreyState::PreyState(int HP, string type, int damage) : HP(HP), type(type), damage(damage){

}

PreyState::~PreyState(){}

int PreyState::getHP() const{
    return HP;
}

string PreyState::getType() const{
    return type;
}

int PreyState::getDamage() const{
    return damage;
}