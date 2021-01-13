#include "LevelTwoState.h"

//constructor and destructor
LevelTwoState::LevelTwoState() : LevelState("level2"){

}

LevelTwoState::~LevelTwoState(){
    
}

//abstract method implementations
void LevelTwoState::handle(){
    cout << "The country is at level2: Take caution" << endl;
}

LevelState* LevelTwoState::changePandemicLevel(bool increase){
    if(increase){
        return new LevelThreeState();
    }
    else{
        return new LevelOneState();
    }
}