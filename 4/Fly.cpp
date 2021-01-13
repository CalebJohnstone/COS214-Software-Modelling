#include "Fly.h"

//constructor and destructor
Fly::Fly(RemoteControlVehicle* receiver) : Command(receiver){

}

Fly::~Fly(){

}

//methods
void Fly::execute(){
   receiver->handleRequest("fly", getApply(), false);
   cout << endl;
}

void Fly::undo(){
    receiver->reverseRequest("fly", getApply(), false);
    cout << endl;
}

string Fly::getApply(){
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