#include "RemoteControlCar.h"
#include "RemoteControlPlane.h"
#include "TurnOn.h"
#include "TurnOff.h"
#include "MoveForward.h"
#include "MoveBackward.h"
#include "Button.h"
#include "RemoteControlRocket.h"
#include "RocketAdapter.h"
#include "Speed.h"
#include "Fly.h"

#include <fstream>

int main(int argc, char** argv){
    //create RemoteControlCar and RemoteControlPlane (Command Pattern)
    RemoteControlCar* car = new RemoteControlCar("Lightning McQueen");
    RemoteControlPlane* plane = new RemoteControlPlane("VSS Unity");

    //create the 4 buttons (one for each command)

    //use the buttons to send commands to the RemoteControlCar and RemoteControlPlane

    //store the buttons in an array
    Button** buttons = new Button*[8];
    
    //car buttons
    buttons[0] = new Button(new TurnOn(car));
    buttons[1] = new Button(new TurnOff(car));
    buttons[2] = new Button(new MoveForward(car));
    buttons[3] = new Button(new MoveBackward(car));

    //plane buttons
    buttons[4] = new Button(new TurnOn(plane));
    buttons[5] = new Button(new TurnOff(plane));
    buttons[6] = new Button(new MoveForward(plane));
    buttons[7] = new Button(new MoveBackward(plane));

    //random seed: first command line argument (defualt value: 501561)
    srand(stoi(argv[1]));

    cout << endl;
    cout << "Pressing buttons on the universal remote to control the RC car and RC plane." << endl;
    cout << endl;

    for(int i = 0; i < 30; ++i){
        int execute = rand() % 2;

        //use the button
        if(execute){
            buttons[rand() % 8]->press();
        }else{
            buttons[rand() % 8]->undoPress();
        }        
    }

    cout << endl;
    cout << "Done using the RC car and the RC plane." << endl;
    cout << "==================================================================" << endl;

    //create RemoteControlRocket
    RemoteControlRocket* rocket = new RemoteControlRocket();

    //create RocketAdapter (Adapter Pattern)
    RocketAdapter* rocketAdapter = new RocketAdapter(rocket);

    //create commands and buttons for rocket
    Button** rocketButtons = new Button*[4];

    rocketButtons[0] = new Button(new TurnOn(rocketAdapter));
    rocketButtons[1] = new Button(new TurnOff(rocketAdapter));
    rocketButtons[2] = new Button(new MoveForward(rocketAdapter));
    rocketButtons[3] = new Button(new MoveBackward(rocketAdapter));

    //random seed: second first command line argument (default value: 427) 
    srand(stoi(argv[2]));

    cout << "Pressing buttons on the universal remote to control the RC rocket." << endl;
    cout << endl;

    //use the RemoteControlRocket using the RocketAdapter in order to treate it like the RemoteControlCar and RemoteControlPlane (the concrete RemoteControlVehicles)
    for(int i = 0; i < 15; ++i){
        int execute = rand() % 2;

        //use the button for the rocket
        if(execute){
            rocketButtons[rand() % 4]->press();
        }else{
            rocketButtons[rand() % 4]->undoPress();
        }      
    }

    cout << endl;
    cout << "Done using the RC rocket." << endl;

    //Chain of Responsibility pattern
    cout << endl;
    cout << "Sending requests to fly and speed: " << endl;
    cout << endl;

    //apply value set in first line of text file: config.txt
    ofstream file("config.txt");
    string apply = argv[3];
    file << apply << endl;

    //link the RemoteControlVehicles to each other
    car->add(plane);
    car->add(rocketAdapter);

    //create extra cars and planes (2 extra each) and add to the list
    car->add(new RemoteControlCar("Chick \"Thunder\" Hicks"));

    RemoteControlPlane* fighterJet = new RemoteControlPlane("Fighter Jet");
    car->add(fighterJet);

    RemoteControlPlane* cropDuster = new RemoteControlPlane("Crop duster");
    car->add(cropDuster);

    car->add(new RemoteControlCar("Ferrari"));

    //create buttons and their respective commands for speeding and flying
    Button* btnSpeed = new Button(new Speed(car));
    Button* btnFly = new Button(new Fly(car));

    //turn on some of the cars and planes to show that the first vehicle to handle the request stops the passing down of responsibility
    Button* btnTurnOnJet = new Button(new TurnOn(fighterJet));
    Button* btnTurnOnCropDuster = new Button(new TurnOn(cropDuster));

    //press the buttons to turn on the 2 extra planes
    btnTurnOnJet->press();
    btnTurnOnCropDuster->press();
    cout << endl;

    //display what <apply> equals
    cout << "<apply> = " << apply << endl;

    //press the buttons to send the requests
    cout << "fly:" << endl;
    btnFly->press();

    cout << "speed:" << endl;
    btnSpeed->press();
    
    //undo the previous 2 button presses
    cout << "undoing fly:" << endl;
    btnFly->undoPress();

    cout << "undoing speed:" << endl;
    btnSpeed->undoPress();

    cout << "Done sending requests" << endl;

    return 0;
}