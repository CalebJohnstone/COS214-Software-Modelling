#ifndef User_H
#define User_H

#include "SocialSiteMediator.h"
#include <iostream>
#include <string>

using namespace std;

class User {
	public:
		User(SocialSiteMediator* mediator, string name);
        void changed(string message);
        string getName();
        virtual void receiveMessage(string message) = 0;
    
    protected:
        SocialSiteMediator* mediator;
        string username;
};

#endif