#include "Pandemic.h"

#include "noLevelState.h"
#include "levelOneState.h"
#include "levelTwoState.h"
#include "levelThreeState.h"
#include "levelFourState.h"
#include "levelFiveState.h"

#define GREEN   "\033[32m"    /* Green */
#define RED     "\033[31m"      /* Red */
#define BLUE    "\033[34m"      /* Blue */
#define RESET   "\033[0m"

int main(int argc, char *argv[]){
    if(argc != 4){
        cout << RED << "main.cpp takes two command line arguments, which are the start level, random number generator seed and the number of operations." << RESET << endl;
        return 0;
    }

    //SECTION A MAIN PROGRAM

    //coronavirus execution determined using command line arguments
    Pandemic* coronavirus = new Pandemic("COVID-19");

    int startLevel = atoi(argv[1]);

    //sets state to be the start level state and the strategy to match
    switch (startLevel) {
        case 1:
            coronavirus->setState(new LevelOneState());
            break;

        case 2:
            coronavirus->setState(new LevelTwoState());
            break;

        case 3:
            coronavirus->setState(new LevelThreeState());
            break;

        case 4:
            coronavirus->setState(new LevelFourState());
            break;

        default:
            coronavirus->setState(new LevelFiveState());
            break;
    }    

    //change seed value to generate different operations
    srand(atoi(argv[2]));

    cout << GREEN << "Starting at level: " << startLevel << endl;
    cout << "Random number generator seed: " << argv[2] << endl;
    cout << "Number of operations: " << argv[3] << endl;
    cout << RESET << endl;

    cout << BLUE << "Pandemic: " << coronavirus->getName() << endl;
    cout << RESET << endl;

    //do argv[2] number of operations
    int x = atoi(argv[3]);

    for(int i = 0; i < x; i++){
        int operation = (rand() % 2) + 1;

        switch (operation) {
            case 1:
                //increase the level
                cout << endl;
                coronavirus->increaseLevel();
                coronavirus->takeAction();
                cout << endl;
                break;

            case 2:
                //decrease the level
                coronavirus->decreaseLevel();
                break;
        }
    }

    cout << endl;
    cout << BLUE << "Done running the operations for " << coronavirus->getName() << endl;
    cout << "==================================================" << endl;
    cout << RESET << endl;

    //Memory free
    delete coronavirus;

    //same execution each time
    Pandemic* slammer = new Pandemic("Slammer Virus");
    slammer->setState(new LevelThreeState());

    cout << BLUE << "Pandemic: " << slammer->getName() << endl;
    cout << "Running 80 change operations ... " << endl;
    cout << RESET << endl;

    bool changes[][8] = {
        {0,0,0,1,0,1,1,1},
        {0,1,1,0,1,1,0,0},
        {0,1,0,0,0,0,1,1},
        {0,0,1,0,1,1,0,1},
        {0,1,0,1,0,1,0,0},
        {1,1,1,1,0,1,1,0},
        {0,0,0,1,0,1,1,1},
        {0,1,0,1,1,0,0,1},
        {1,1,0,0,0,0,0,1},
        {1,0,0,1,1,0,1,0}
    };

    //do 80 operations
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 8; j++){
            switch (changes[i][j]) {
                case 0:
                    cout << endl;
                    slammer->increaseLevel();
                    slammer->takeAction();
                    cout << endl;
                    break;
                case 1:
                    slammer->decreaseLevel();
                    break;
            }
        }
    }

    cout << BLUE << "Done running the operations for " << slammer->getName() << endl;
    cout <<  "==================================================" << RESET << endl;

    delete slammer;

    return 0;
}