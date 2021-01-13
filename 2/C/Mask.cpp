#include "Mask.h"

//constructor and destructor
Mask::Mask(){

}

Mask::~Mask(){

}

void Mask::drawPoster(){
    //print the mask addition
    cout << " ///        **      **          ///" << endl;
    cout << "  ///      *  *    *  *        /// " << endl;
    cout << "   ///      **      **        ///  " << endl;
    cout << "    ////////////////////////////   " << endl;
    cout << "    ///////////////////////////    " << endl;
    cout << "     /////////////////////////     " << endl;
    cout << "      //////////////////////       " << endl;
    cout << "       ////////////////////        " << endl;
    cout << "         ///////////////           " << endl;
    cout << "           ///////////             " << endl;
    cout << " " << endl;
    cout << "    HELP OTHERS BY WEARING A MASK  " << endl;
    cout << " " << endl;

    //print the next addition in the chain
    this->addition->drawPoster();
}