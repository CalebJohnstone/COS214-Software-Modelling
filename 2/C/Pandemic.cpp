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

        setPoster();
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

        setPoster();
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

    //set the poster
    setPoster();
}

//SECTION C
void Pandemic::setPoster(){
    //set the poster
    if(poster){
        delete poster;
    }

    string level = state->getPandemicState();

    //create the new poster
    poster = new BaseImage(level + "Poster.txt");

    //add the necessary ImageAdditions depending on the level

    /*
    Rules:

    - always wash hands
    - can stop using hand sanitiser at no level
    - can stop wearing a mask at level 1
    - can stop checking temperature at level 2

    --> display different text (the ImageElements) for each level
    */

    //always wash hands
   poster->addToElement(1, new WashHands());

   if(level != "none"){
       stringstream ss(level[level.length()-1] + "");
       int levelNum;
       ss >> levelNum;

       if(levelNum >= 1){
           //add hand sanitiser
           poster->addToElement(1, new UseHandSanitiser());
       }

       if(levelNum >= 2){
           //add mask
           poster->addToElement(1, new Mask());
       }

       if(levelNum >= 3){
           //add temperature check
           poster->addToElement(1, new TemperatureCheck());
       }

   }

    //display the poster
    poster->drawPoster();
}