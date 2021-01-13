#include "Pandemic.h"

//constructor
Pandemic::Pandemic(string name) : name(name){

}

//destructor
Pandemic::~Pandemic(){

}

string Pandemic::getName() const{
    return name;
}

void Pandemic::increaseLevel(){
    //check for the level being level5
    if(state == nullptr){
        cout << "The state has not been set yet for " << this->name << ". Cannot increase the level." << endl;
    }
    else if(state->getPandemicState() == "level5"){
        cout << "The country is at level 5: The level cannot be increased." << endl;
    }
    else{
        state = state->changePandemicLevel(true);
        state->handle();

        //update the PandemicStrategy
        if(strategy){
            delete strategy;
        }    

        string level = state->getPandemicState();
        
        if(level == "level1"){
            strategy = new levelOneStrategy();
        }
        else if(level == "level2"){
            strategy = new levelTwoStrategy();
        }
        else if(level == "level3"){
            strategy = new levelThreeStrategy();
        }
        else if(level == "level4"){
            strategy = new levelFourStrategy();
        }
        else{
            strategy = new levelFiveStrategy();
        }
    }
}

void Pandemic::decreaseLevel(){
    //check for the level being none
    if(state == nullptr){
        cout << "The state has not been set yet for " << this->name << ". Cannot decrease the level." << endl;
    }
    else if(state->getPandemicState() == "none"){
        cout << "The country is at no level: The level cannot be decreased." << endl;
    }
    else{
        state = state->changePandemicLevel(false);
        state->handle();

        //update the PandemicStrategy
        delete strategy;

        string level = state->getPandemicState();
        
        if(level == "none"){
            //no level has no strategy class
            strategy = nullptr;
        }
        else if(level == "level1"){
            strategy = new levelOneStrategy();
        }
        else if(level == "level2"){
            strategy = new levelTwoStrategy();
        }
        else if(level == "level3"){
            strategy = new levelThreeStrategy();
        }
        else{
            strategy = new levelFourStrategy();
        }
    }
}

void Pandemic::takeAction(){
    cout << this->name << strategy->takeAction() << endl;
}

void Pandemic::setState(LevelState* state){
    if(this->state){
        delete this->state;
    }
    
    this->state = state;

    if(this->strategy){
        delete this->strategy;
    }

    string level = state->getPandemicState();

    if(level == "none"){
        //no level has no strategy class
        strategy = nullptr;
    }
    else if(level == "level1"){
        strategy = new levelOneStrategy();
    }
    else if(level == "level2"){
        strategy = new levelTwoStrategy();
    }
    else if(level == "level3"){
        strategy = new levelThreeStrategy();
    }
    else if(level == "level4"){
        strategy = new levelFourStrategy();
    }
    else{//level5
        strategy = new levelFiveStrategy();
    }
}