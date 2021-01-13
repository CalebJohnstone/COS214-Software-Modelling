#include "TemperatureCheck.h"

//constructor and destructor
TemperatureCheck::TemperatureCheck(){

}

TemperatureCheck::~TemperatureCheck(){

}

void TemperatureCheck::drawPoster(){
    cout << "             ________________________________________________________" << endl;
    cout << "       ____.-'':':':':':':':':':':':':':':':':':':':':':':':':':':'-." << endl;
    cout << "     (___:'   '   '   '   '   '   '  '   '   '   '   '   '  ========)" << endl;
    cout << "          .__39.25____39____38.75____38.5______38.25_____38_____37.75" << endl;
    cout << " " << endl;
    cout << " Check your temperature if you are not feeling well" << endl;
    cout << " " << endl;

    //print the next addition in the chain
    this->addition->drawPoster();
}