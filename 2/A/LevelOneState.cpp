#include "LevelOneState.h"

//constructor and destructor
LevelOneState::LevelOneState() : LevelState("level1"){

}

LevelOneState::~LevelOneState(){

}

//abstract method implementations
void LevelOneState::handle(){
    cout << "The country is at level1: Very few cases" << endl;
}

LevelState* LevelOneState::changePandemicLevel(bool increase){
    if(increase){
        return new LevelTwoState();
    }
    else{
        return new NoLevelState();
    }
}