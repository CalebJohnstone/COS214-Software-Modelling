#include "PrisonArea.h"

PrisonArea::PrisonArea(int width, int height) : mWidth(width), mHeight(height){
    //mPrisoner is put in the middle of the prison area
    mPrisoner = new Prisoner(mWidth/2, mHeight/2);

    //create 4 border guards   
    
    //top-left corner
    mBorderGuard.push_back(new BorderGuard(0, 0, mPrisoner));

    //top-right corner
    mBorderGuard.push_back(new BorderGuard(mWidth-1, 0, mPrisoner));

    //bottom-left corner
    mBorderGuard.push_back(new BorderGuard(0, mHeight-1, mPrisoner));

    //bottom-right corner
    mBorderGuard.push_back(new BorderGuard(mWidth-1, mHeight-1, mPrisoner));

    //attach the BorderGuards to the prisoner
    for(vector<BorderGuard*>::iterator it = mBorderGuard.begin(); it != mBorderGuard.end(); ++it){
        mPrisoner->attach(*it);
    }
}

PrisonArea::~PrisonArea(){
    delete mPrisoner;

    for(vector<BorderGuard*>::iterator it = mBorderGuard.begin(); it != mBorderGuard.end(); ++it){
        delete *it;
        *it = nullptr;
    }
}

int PrisonArea::getWidth() const{
    return mWidth;
}

int PrisonArea::getHeight() const{
    return mHeight;
}

Prisoner* PrisonArea::getPrisoner() const{
    return mPrisoner;
}

void PrisonArea::print(){
    for(int y = 0; y < mHeight; ++y){
        for(int x = 0; x < mWidth; ++x){
            char value = ' ';

            if(x == mPrisoner->getX() && y == mPrisoner->getY()){
                value = mPrisoner->getValue();
            }
            else{
                for(int i = 0; i < mBorderGuard.size(); ++i){
                    if(x == mBorderGuard[i]->getX() && y == mBorderGuard[i]->getY()){
                        value = mBorderGuard[i]->getValue();
                        break;
                    }
                    else if(x == mBorderGuard[i]->getX() && y == mBorderGuard[i]->getY()){
                        value = '*';
                    }
                }
            }

            cout << value;
        }

        cout << endl;
    }
}