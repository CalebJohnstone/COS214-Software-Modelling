#include "PrisonArea.h"
#define size(type) ((char *)(&type+1)-(char*)(&type))

int main(){
    //read input moves from an array
    Prisoner::Direction moves[] = {
    Prisoner::Direction::up, 
    Prisoner::Direction::left, 
    Prisoner::Direction::left, 
    Prisoner::Direction::down, 
    Prisoner::Direction::down, 
    Prisoner::Direction::down, 
    Prisoner::Direction::right, 
    Prisoner::Direction::left, 
    Prisoner::Direction::left, 
    Prisoner::Direction::left
    };

    //create the prison area
    PrisonArea* area = new PrisonArea(5, 5);
    area->print();

    //get the prisoner and move them using the moves[]
    Prisoner* prisoner = area->getPrisoner();

    for(int i = 0; i < size(moves)/size(moves[0]); i++){
        //move the prisoner
        prisoner->runTowards(moves[i]);

        //update the prison Area display
        cout << endl;
        cout << "--printing--" << endl;
        area->print();
    }

    return 0;
}