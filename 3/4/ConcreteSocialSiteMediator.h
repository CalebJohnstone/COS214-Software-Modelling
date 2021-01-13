#ifndef ConcreteSocialSiteMediator_H
#define ConcreteSocialSiteMediator_H

#include <iostream>
#include <string>

#include "SocialSiteUser.h"

using namespace std;

class ConcreteSocialSiteMediator : public SocialSiteMediator {
	public:
		ConcreteSocialSiteMediator();
        ~ConcreteSocialSiteMediator();
        virtual void notify(User* username, string message);
        virtual bool addUser(string username);
        User* getUser(string name);
    
    private:
        User** users;
        int numUsers;
};

#endif