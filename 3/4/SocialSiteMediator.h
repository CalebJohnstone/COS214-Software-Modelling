#ifndef SocialSiteMediator_H
#define SocialSiteMediator_H

#include <iostream>
#include <string>

#include "User.h"

class User;

using namespace std;

class SocialSiteMediator {
	public:
		SocialSiteMediator(){}
        virtual void notify(User* username, string message) = 0;
        virtual bool addUser(string username) = 0;
};

#endif