#include "WashHands.h"

//constructor and destructor
WashHands::WashHands(){

}

WashHands::~WashHands(){

}

void WashHands::drawPoster(){
    cout << "      ," << endl;
    cout << "   ,'   `." << endl;
    cout << "  %       %" << endl;
    cout << "  :        :" << endl;
    cout << "  \".     .\"" << endl;
    cout << "    `-.-'" << endl;
    cout << " " << endl;
    cout << " WASH YOUR HANDS" << endl;
    cout << " " << endl;

    //print the next addition in the chain
    this->addition->drawPoster();
}