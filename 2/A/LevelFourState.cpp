#include "LevelFourState.h"

//constructor and destructor
LevelFourState::LevelFourState() : LevelState("level4"){

}

LevelFourState::~LevelFourState(){

}

//abstract method implementations
void LevelFourState::handle(){
    cout << "The country is at level4: There are quite a bit of cases, take all necessary precautions." << endl;
}

LevelState* LevelFourState::changePandemicLevel(bool increase){
    if(increase){
        return new LevelFiveState();
    }
    else{
        return new LevelThreeState();
    }
}