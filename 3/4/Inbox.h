#ifndef Inbox_H
#define Inbox_H

#include <iostream>
#include <string>

using namespace std;

class Inbox {
	public:
		Inbox(int _MaxMessages);
        ~Inbox();
        void save(string message);
        string load(int index);
        int getNumMessages();

    private:
        int numMessages;
        int MaxMessages;
        string* messages;
};

#endif