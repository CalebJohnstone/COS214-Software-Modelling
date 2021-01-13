#ifndef PrisonArea_H
#define PrisonArea_H

#include <iostream>
#include <vector>

#include "Prisoner.h"
#include "BorderGuard.h"

using namespace std;

class PrisonArea{
	public:
		PrisonArea(int width, int height);
    ~PrisonArea();
    int getWidth() const;
    int getHeight() const;
    Prisoner* getPrisoner() const;
    void print();

    private:
      int mWidth;
      int mHeight;
      Prisoner* mPrisoner;
      vector<BorderGuard*> mBorderGuard;
};

#endif