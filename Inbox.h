#include <iostream>
#include <string>

using namespace std;

#ifndef INBOX_H
#define INBOX_H

struct node{
    node* prev;
    node* next;
    string subject;    
    unsigned int quantity;
};

class Inbox {
    public:
    
    Inbox();
    ~Inbox();
    void InsertComm(string);
    void DisplayInbox();
    
    private:
    node* head;
    node* tail;
    unsigned int size;
    node* SearchCommunication(string);
    int GetQuantity();
};

#endif //INBOX_H
