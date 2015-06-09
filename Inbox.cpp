#include "Inbox.h"
#include "EmailList.h"
#include <iostream>
#include <string>

using namespace std;

//Constructor
Inbox::Inbox(){
    head = NULL;
    tail = NULL;
    size = 0;
};


//Destructor
Inbox::~Inbox(){
    while(head){
        delete head->prev;
        inboxnode* temp = head->next;
        delete head->next;
        head = temp;
    }
    delete head;
    delete tail;
}


inboxnode* Inbox::SearchCommunication(string key) {
    inboxnode* curr = head;
    while(curr){
        if (!key.compare(curr->subject)){
            return curr;
        }
        curr = curr->next;
    }
    return curr;
}

int Inbox::GetQuantity(){
    unsigned int count = 0;
    while(head){
        count += head->quantity;
        head = head->next;
    }
    return count;
}

//Inserts a communication into the list
void Inbox::InsertComm(string comm){
    if(size == 0){
        inboxnode* newnode = new inboxnode();
        head = newNode;
        tail = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->subject = comm;
        newNode->quantity = 1;
        size++;
    }
    
    else if(size == 1){
        if(!SearchCommunication(comm)){
            inboxnode* newNode = new inboxnode();
            newNode->subject = comm;
            newNode->quantity = 1;
            head->prev = newNode;
            newNode->next = head;
            newNode->prev = NULL;
            
            head = newNode;
            size++;
        }
        else{
            head->quantity += 1;
        }
    }
    
    else if (size > 1){
        inboxnode* match = SearchCommunication(comm);
        if(match){
            if(match == tail){
                tail->quantity += 1;
                tail->prev->next = NULL;
                tail->next = head;
                head->prev = tail;
                tail = tail->prev;
                head = head->prev;
                head->prev = NULL;
            }
            else if (match == head){
                head->quantity += 1;
            }
            else{
                match->quantity += 1;
                match->prev->next = match->next;
                match->next->prev = match->prev;
                head->prev = match;
                match->next = head;
                head = match;
                head->prev = NULL;
            }
        }
        else{
            inboxnode* newNode = new inboxnode();
            newNode->subject = comm;
            newNode->quantity = 1;
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            size++;
        }
    }
}

//Prints the contents of the Inbox to the screen
void Inbox::DisplayInbox(){
    inboxnode* curr = head;
    cout << "Inbox: Total number of emails is " << GetQuantity() << "." << endl << endl;
    while(curr){
        cout << curr->subject << "-" << curr->quantity << " email(s)" << endl;
        if(!curr->next){
            return;
        }
        curr = curr->next;
    }
}
