#include "LevelFiveState.h"

//constructor and destructor
LevelFiveState::LevelFiveState() : LevelState("level5"){

}

LevelFiveState::~LevelFiveState(){

}

//abstract method implementations
void LevelFiveState::handle(){
    cout << "The country is at level5: Don’t go outside unless you have to" << endl;
}

LevelState* LevelFiveState::changePandemicLevel(bool increase){
    if(increase){
        return new LevelFiveState();
    }
    else{
        return new LevelFourState();
    }
}