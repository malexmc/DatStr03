#include "EmailList.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef INBOX_H
#define INBOX_H

struct inboxnode{
    inboxnode* prev;
    inboxnode* next;
    string subject;    
    EmailList* emailHead;
    unsigned int quantity;
};


class Inbox {
    public:
    
    Inbox();
    ~Inbox();
    void InsertComm(string);
    void DisplayInbox();
    
    private:
    inboxnode* head;
    inboxnode* tail;
    unsigned int size;
    inboxnode* SearchCommunication(string);
    int GetQuantity();
};

#endif //INBOX_H
