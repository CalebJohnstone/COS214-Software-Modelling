#include "LevelState.h"

//constructor and destructor
LevelState::LevelState(string pandemicLevel) : pandemicLevel(pandemicLevel){
    
}

LevelState::~LevelState(){

}

//methods
string LevelState::getPandemicState() const{
    return pandemicLevel;
}