#include <assert.h>
#include "Prey.h"
#include "Lion.h"
#include "Cheetah.h"
#include "Wolf.h"
#include "WildDog.h"
#include "LionFactory.h"
#include "CheetahFactory.h"
#include "WolfFactory.h"
#include "WildDogFactory.h"

#include "PreyStore.h"
#include "PredatorStore.h"

void runSimulations(Prey** preyArray, int numberOfPrey, Predator** p, int numberOfPredators){
    //save the Prey and Predators created in their respective stores
    PreyStore* preyStore = new PreyStore(numberOfPrey);

    //add the PreyMementos to preyStore
    for(int j = 0; j < numberOfPrey; j++){
        preyStore->addMemento(preyArray[j]->createMemento());
    }

    PredatorStore* predatorStore = new PredatorStore(numberOfPredators);

    //add the PredatorMementos to the predatorStore
    for(int i = 0; i < numberOfPredators; i++){
        predatorStore->addMemento(p[i]->createMemento());
    }

    //table for all of the results of the hunting simulations
    bool** results = new bool*[numberOfPredators];
    
    for(int i = 0; i < numberOfPredators; i++){
        results[i] = new bool[numberOfPrey];
    }

    for (int i = 0; i < numberOfPredators; i++)
    {
        for(int j = 0; j < numberOfPrey; j++){
            //re-instate the Predator to its original state
            p[i]->setMemento(predatorStore->getMemento(i));

            //re-instate the Prey to its original state
            preyArray[j]->setMemento(preyStore->getMemento(j));

            //Predator hunts the Prey
            p[i]->hunt(preyArray[j]);

            //output who won
            cout << (p[i]->getHP() > 0 ? "Predator Wins" : "Prey Wins") << endl;

            //store the result of the simulation -> false: loss, true: win
            results[i][j] = p[i]->getHP() > 0;
        }
    }

    //summarise the outcomes of each simulation in a numberOfPredators x numberOfPrey table (8x2 in the case use in main())
    cout << endl;
    cout << "Printing the results of all of the hunting simulations" << endl;

    //output the column headings
    cout << "Predator";

    for(int j = 0; j < numberOfPrey; j++){
        cout << "\t" << preyArray[j]->getType();
    }

    cout << endl << endl;

    for(int i = 0; i < numberOfPredators; i++){
        //output the type of Predator
        cout << p[i]->getType() << "\t";

        for(int j = 0; j < numberOfPrey; j++){
            //output the result of the hunt between the current Predator and Prey combination
            cout << "\t" << ((results[i][j]) ? "WIN" : "LOSS");
        }

        cout << endl;
    }

    //de-allocate the results array
    for(int i = 0; i < numberOfPredators; i++){
        delete[] results[i];
    }

    delete[] results;
    results = nullptr;

    //de-allocate the stores
    delete predatorStore;
    predatorStore = nullptr;

    delete preyStore;
    preyStore = nullptr;
}

int main()
{
    /************************************************************/
    /************************** TASK 1 **************************/
    /************************************************************/

    //added using the stores --> here we declare the Predator objects by calling their constructors
    cout << "Using Predator subclass objects" << endl;
    cout << endl;

    Predator **p = new Predator *[4];
    p[0] = new Lion("Stalk", "Short charge");
    p[1] = new Cheetah("Sneak", "Speed");
    p[2] = new Wolf("Surround", "Bite");
    p[3] = new WildDog("Run", "Pounce");

    Prey** preyArray = new Prey*[2];
    preyArray[0] = new Prey(15, "Bok", 10);
    preyArray[1] = new Prey(20, "Deer", 12);

    //run the simulations --> put into a function (since we do this twice)
    runSimulations(preyArray, 2, p, 4);

    // Memory free
    for (int i = 0; i < 4; i++)
        delete p[i];

    delete[] p;
    p = nullptr;
    cout << endl;

    /************************************************************/
    /************************** TASK 2 **************************/
    /************************************************************/

    //added using the stores --> here we declare the Predator objects by using their respective factory
    cout << "Using the Predator subclass Factories" << endl;
    cout << endl;

    p = new Predator *[4];
    
    PredatorFactory **pf = new PredatorFactory *[4];
    pf[0] = new LionFactory();
    pf[1] = new CheetahFactory();
    pf[2] = new WolfFactory();
    pf[3] = new WildDogFactory();
    cout << endl;

    //SAVE THE PREDATORS AND PREY CREATED
    preyArray = new Prey*[2];
    preyArray[0] = new Prey(35, "Gazelle", 15);
    preyArray[1] = new Prey(25, "Antelope", 18);

    for (int i = 0; i < 4; i++){
        //use the current PredatorFactory to produce a Predator and store it in the p array
        p[i] = pf[i]->createPredator("Hunting Method", "Speciality");// ***
    }

    //run the simulations
    runSimulations(preyArray, 2, p, 4);

    // Memory free
    for (int i = 0; i < 4; i++)
    {
        delete p[i];
        delete pf[i];
    }

    delete[] p;
    delete[] pf;
    p = nullptr;
    pf = nullptr;
    cout << endl;

    /************************************************************/
    /************************** TASK 3 **************************/
    /************************************************************/

    /**
     * NB: Assertions are used here to test code, if an assertion fails, please check your clone method.
     */

    cout << "Task 3 -> cloning a prey" << endl;
    Prey* bok = new Prey(15, "Bok", 10);
    Prey *clonedPrey = bok->clone();

    assert(bok != clonedPrey);

    cout << "Prey 1:\nHP:\t\t" << bok->getHP() << "\nDamage:\t\t" << bok->getDamage() << "\nType:\t\t" << bok->getType() << endl;
    cout << "Prey 2:\nHP:\t\t" << clonedPrey->getHP() << "\nDamage:\t\t" << clonedPrey->getDamage() << "\nType:\t\t" << clonedPrey->getType() << endl
         << endl;

    assert(bok->getHP() == clonedPrey->getHP());
    assert(bok->getDamage() == clonedPrey->getDamage());
    assert(bok->getType() == clonedPrey->getType());

    bok->setHP(5);
    bok->setDamage(5);
    bok->setType("Buffalo");

    cout << "Prey 1:\nHP:\t\t" << bok->getHP() << "\nDamage:\t\t" << bok->getDamage() << "\nType:\t\t" << bok->getType() << endl;
    cout << "Prey 2:\nHP:\t\t" << clonedPrey->getHP() << "\nDamage:\t\t" << clonedPrey->getDamage() << "\nType:\t\t" << clonedPrey->getType() << endl
         << endl;

    assert(bok->getHP() != clonedPrey->getHP());
    assert(bok->getDamage() != clonedPrey->getDamage());
    assert(bok->getType() != clonedPrey->getType());

    delete clonedPrey;
    delete bok;
    clonedPrey = nullptr;
    bok = nullptr;
    cout << endl;

    /************************************************************/
    /************************** TASK 4 **************************/
    /************************************************************/

    /*cout << "Task 4 -> single hunt simulation" << endl;
    bok = new Prey(15, "Bok", 10);
    p = new Predator *[1];
    pf = new PredatorFactory *[1];
    pf[0] = new LionFactory();

    p[0] = pf[0]->createPredator("Lions Hunting Method", "Lions Speciality");
    p[0]->hunt(bok);
    cout << (p[0]->getHP() > 0 ? "Predator Wins" : "Prey Wins") << endl;

    delete p[0];
    delete pf[0];
    delete[] p;
    delete bok;
    delete[] pf;
    p = nullptr;
    bok = nullptr;
    pf = nullptr;
    cout << endl;*/

    return 0;
}