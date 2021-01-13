#include "LevelThreeState.h"

//constructor and destructor
LevelThreeState::LevelThreeState() : LevelState("level3"){

}

LevelThreeState::~LevelThreeState(){

}

//abstract method implementations
void LevelThreeState::handle(){
    cout << "The country is at level3: Moderate number of cases, make sure you are wearing a mask" << endl;
}

LevelState* LevelThreeState::changePandemicLevel(bool increase){
    if(increase){
        return new LevelFourState();
    }
    else{
        return new LevelTwoState();
    }
}