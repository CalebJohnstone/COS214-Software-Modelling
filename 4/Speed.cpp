#include "Speed.h"

//constructor and destructor
Speed::Speed(RemoteControlVehicle* receiver) : Command(receiver){

}

Speed::~Speed(){

}

//methods
void Speed::execute(){
   receiver->handleRequest("speed", getApply(), false);
   cout << endl;
}

void Speed::undo(){
    receiver->reverseRequest("speed", getApply(), false);
    cout << endl;
}

string Speed::getApply(){
    //read the value of apply from the textfile: config.txt
    ifstream file("config.txt");
    string apply;

    if(file.is_open()){
        getline(file, apply);
    }else{
       cout << "Unable to open the textfile called: config.txt" << endl;
   }

   file.close();
   return apply;
}