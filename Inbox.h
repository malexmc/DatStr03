#ifndef INBOX_H
#define INBOX_H

#include "EmailList.h"
#include <iostream>
#include <string>

using namespace std;

struct InboxNode {
    InboxNode* prev;
    InboxNode* next;
    string subject;    
    EmailList* emailList;

	// <will>
	// I renamed this from quantity to numberOfEmails just to be a little more specific. Also, I know it says to have this field 
	// in the homework doc, but can't we just query from the EmailList? Let's bring this up to Anca.
    unsigned int numberOfEmails;
};

class Inbox {
public:
    Inbox();
	Inbox(const Inbox&);
    ~Inbox();

	// <will>
	// Renamed from InsertComm() to InsertEmail()
    void InsertEmail(string);
	void DeleteCommunication(string);

    void DisplayInbox();

	// <will>
	// PrintLinkedList() is a debugging function.
	void PrintLinkedList();
    
private:
    InboxNode* head;
    InboxNode* tail;
    unsigned int size;

	InboxNode* SearchCommunication(string subjectToFind);

	// <will>
	// GetTotalNumberOfEmails() is renamed from GetQuantity(). 
	// I also added CreateNewInboxNode() to assist in creating new inbox nodes.
    int GetTotalNumberOfEmails();
	InboxNode* CreateNewInboxNode(InboxNode* prev, InboxNode* next, string subject, int numberOfEmails);
};

#endif //INBOX_H
