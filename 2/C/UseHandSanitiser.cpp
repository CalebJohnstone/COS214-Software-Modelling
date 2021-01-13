#include "UseHandSanitiser.h"

//constructor and destructor
UseHandSanitiser::UseHandSanitiser(){

}

UseHandSanitiser::~UseHandSanitiser(){

}

void UseHandSanitiser::drawPoster(){
    cout << "    [_ ]" << endl;
    cout << "  .-'. '-." << endl;
    cout << " /:;/ _.-'\\" << endl;
    cout << " |:._   .-|" << endl;
    cout << " |:._     |" << endl;
    cout << " |:._ +++ |" << endl;
    cout << " |:._ +++ |" << endl;
    cout << " |:._ +++ |" << endl;
    cout << " `-.____.-'" << endl;
    cout << " " << endl;
    cout << " Use Hand Sanitiser" << endl;
    cout << " " << endl;

    //print the next addition in the chain
    this->addition->drawPoster();
}