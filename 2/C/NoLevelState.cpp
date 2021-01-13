#include "NoLevelState.h"

//constructor and destructor
NoLevelState::NoLevelState() : LevelState("none"){

}

NoLevelState::~NoLevelState(){

}

//abstract method implementations
void NoLevelState::handle(){
    cout << "The country is at no level: Normal Living" << endl;
}

LevelState* NoLevelState::changePandemicLevel(bool increase){
    if(increase){
        return new LevelOneState();
    }
    else{
        return new NoLevelState();
    }
}