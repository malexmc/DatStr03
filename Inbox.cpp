//#include "stdafx.h"

#include "Inbox.h"
#include "EmailList.h"
#include <iostream>
#include <string>

using namespace std;

//Constructor

Inbox::Inbox() {
    head = 0;
    tail = 0;
    size = 0;
};

Inbox::Inbox(const Inbox& other) {
    // <will>
    // The size will be changed during the calls to InsertEmail() later.
    size = 0;

    // <will>
    // Since the communications are stored kind of as a stack, we're going to start from the back of other and push
    // the communications onto the new instance in reverse order. This will actually get us the proper order.
    InboxNode* curr = other.tail;
    while (curr != 0) {
        // <will>
        // The InsertEmail() function should eventually take in the new node. Right now, it just takes in the subject.
        /*InboxNode* newNode = new InboxNode;
        newNode->subject = curr->subject;
        newNode->numberOfEmails = curr->numberOfEmails;
        newNode->emailList = new EmailList(curr->emailList);
        InsertEmail(newNode);*/
        InsertEmail(curr->subject);

        curr = curr->prev;
    }
}

//Destructor

Inbox::~Inbox() {
    while (head) {
        InboxNode* temp = head->next;
        delete head->emailList;
        head->emailList = 0;
        delete head;
        head = 0;
        head = temp;
    }
}

// <will>
// I rewrote this function to go with my adjusted InsertEmail method.
// Just switch the comments to go back and forth between the two.
/*InboxNode* Inbox::SearchCommunication(string key) {
    InboxNode* curr = head;
    while(curr){
        if (!key.compare(curr->subject)){
            return curr;
        }
        curr = curr->next;
    }
    return curr;
}*/

void Inbox::DeleteCommunication(string subjectToDelete) {
    InboxNode* nodeToDelete = SearchCommunication(subjectToDelete);
    if (nodeToDelete == 0) {
        return;
    }

    // <will>
    // If we are the head or the tail, adjust those values accordingly.
    if (nodeToDelete == head) {
        head = nodeToDelete->next;
    }
    if (nodeToDelete == tail) {
        tail = nodeToDelete->prev;
    }

    // <will>
    // Have the adjacent nodes point around this one
    InboxNode* previousNode = nodeToDelete->prev;
    InboxNode* nextNode = nodeToDelete->next;

    if (previousNode != 0) {
        previousNode->next = nextNode;
    }
    if (nextNode != 0) {
        nextNode->prev = previousNode;
    }
    
    delete nodeToDelete->emailList;
    nodeToDelete->emailList = 0;
    delete nodeToDelete;
    nodeToDelete = 0;
}

InboxNode* Inbox::SearchCommunication(string subjectToFind) {
    InboxNode* curr = head;

    // <will>
    // Loop while we have more nodes to check
    while (curr != 0) {
        // <will>
        // string::compare returns 0 if they are equal. If they are, return the current node
        if (subjectToFind.compare(curr->subject) == 0) {
            return curr;
        }

        curr = curr->next;
    }
    // <will>
    // If we got here, we didn't find a communication with the given subject.
    return 0;
}

// <will>
// I just renamed this function from GetQuantity() so it would be a little more descriptive.
int Inbox::GetTotalNumberOfEmails() {
    unsigned int count = 0;
    InboxNode* temp = head;
    while (temp) {
        count += temp->numberOfEmails;
        temp = temp->next;
    }
    return count;
}

//Inserts a communication into the list
// <will>
// You list the parameter as "comm", but isn't it actually the subject?
// Also, this will probably need to change in the future to support emails instead of just subjects.
// I actually went ahead and rewrote the function to remove some of the boilerplate. My version has
// a lot less copy/paste sort of stuff going on, and it commented thouroughly, so I think we should use
// it moving forward. If you disagree, let's discuss.

/*void Inbox::InsertEmail(string comm){
    if(size == 0) {
                InboxNode* newNode = new InboxNode();
        head = newNode;
        tail = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->subject = comm;
        newNode->numberOfEmails = 1;
        size++;
    }
    
    else if(size == 1){
        if(!SearchCommunication(comm)){
            InboxNode* newNode = new InboxNode();
            newNode->subject = comm;
                        newNode->numberOfEmails = 1;
            head->prev = newNode;
            newNode->next = head;
            newNode->prev = NULL;
            
            head = newNode;
            size++;
        }
        else{
            head->numberOfEmails += 1;
        }
    }
    
    else if (size > 1){
        InboxNode* match = SearchCommunication(comm);
        if(match){
            if(match == tail){
                tail->numberOfEmails += 1;
                tail->prev->next = NULL;
                tail->next = head;
                head->prev = tail;
                tail = tail->prev;
                head = head->prev;
                head->prev = NULL;
            }
            else if (match == head){
                head->numberOfEmails += 1;
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
                        InboxNode* newNode = new InboxNode();
            newNode->subject = comm;
            newNode->quantity = 1;
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            size++;
        }
    }
}*/

void Inbox::InsertEmail(string subject) {
    InboxNode* match = SearchCommunication(subject);

    // <will>
    // If the match is null, there is no communication for this subject yet, so add it.
    if (match == 0) {
        // <will>
        // Create a new node at the head of the list. The node has:
        //	NULL as its previous node
        //	the current head as its next node (this will be NULL if there are no other nodes)
        //	the given subject as its subject
        //	a new EmailList instance as its email list
        //	a number of emails of 1
        // Add the email to the emailList (not for this assignment).
        InboxNode* newNode = CreateNewInboxNode(0, head, subject, 1);
        //newNode->emailList->Insert(THE_NEW_EMAIL);

        // <will>
        // Set the current head's prev field to this new node (assuming head is not NULL).
        // Set the head pointer to the new node.
        // Increment the total size.
        if (head != 0) {
            head->prev = newNode;
        }
        head = newNode;
        size++;

        // <will>
        // If the size is now 1, then this is also the tail.
        if (size == 1) {
            tail = newNode;
        }
    }

        // <will>
        // Otherwise, we already have a communication for this subject, and so we need to move that communication to the front
        // and add the new email to it.
    else {
        // <will>
        // Increment the number of emails.
        // Add the new email to the emailList (not for this assignment)
        match->numberOfEmails++;
        //match->emailList->Insert(THE_NEW_EMAIL);

        // <will>
        // Additional processing if we are not currently the head.
        // Note that this ensures a length of at least 2.
        if (match != head) {
            // <will>
            // If we are currently the tail, update the tail to the node before us.
            // Note the corner case here; if we are both the head and the tail, this could
            // cause problems since we'll be setting the tail back to NULL. However, we 
            // already checked to make sure we weren't the haed, so it should be safe.
            if (tail == match) {
                tail = match->prev;
            }

            // <will>
            // Remove the match from wherever it is in the list.
            InboxNode* previousNode = match->prev;
            InboxNode* nextNode = match->next;

            // <will>
            // Set the previousNode's next to the next node.
            // Note that previousNode should always not be NULL, since we 
            // already checked to make sure we weren't the head.
            previousNode->next = nextNode;

            // <will>
            // If we are not the tail, set nextNode's previous to the previous node.
            if (nextNode != 0) {
                nextNode->prev = previousNode;
            }

            // <will>
            // Set the current node's prev field to NULL.
            // Set the current node's next field to the current head.
            match->prev = 0;
            match->next = head;

            // <will>
            // Set the current head's prev field to the current node.
            // Set the head pointer to the new node.
            head->prev = match;
            head = match;
        }
    }
}

// <will>
// Create a new node with the given fields set. The node is dynamically allocated and must be
// cleaned up by the caller.
InboxNode* Inbox::CreateNewInboxNode(InboxNode* prev, InboxNode* next, string subject, int numberOfEmails) {
    InboxNode* newNode = new InboxNode;
    newNode->prev = prev;
    newNode->next = next;
    newNode->subject = subject;
    newNode->numberOfEmails = numberOfEmails;

    // <will>
    // Create a new EmailList for the new node.
    newNode->emailList = new EmailList(subject);

    return newNode;
}

//Prints the contents of the Inbox to the screen
void Inbox::DisplayInbox() {
    InboxNode* curr = head;
    cout << "Inbox: Total number of emails is " << GetTotalNumberOfEmails() << "." << endl << endl;

    // <alex>
    // Loop through all the communications and print the number of emails for each.
    while (curr != 0) {
        cout << curr->subject << "-" << curr->numberOfEmails << " email(s)" << endl;
        curr = curr->next;
    }
}

// <will>
// Prints the data for the linked list. For debugging purposes.

void Inbox::PrintLinkedList() {
    // <will>
    // Print head info.
    if (head == 0) {
        cout << "Head is NULL." << endl;
    } else {
        cout << "Head points to the " << head->subject << " communication." << endl;
    }

    // <will>
    // Print tail info.
    if (tail == 0) {
        cout << "Tail is NULL." << endl;
    } else {
        cout << "Tail points to the " << tail->subject << " communication." << endl;
    }

    // <will>
    // Print the linked list itself.
    InboxNode* curr = head;
    cout << "Begin list (of size " << size << ")." << endl;
    while (curr != 0) {
        cout << "Subject: " << curr->subject << " - Num Emails: " << curr->numberOfEmails << " - Prev: ";

        // <will>
        // Print either the previous node's subject or NULL if there is not a previous node.
        if (curr->prev != 0) {
            cout << curr->prev->subject;
        } else {
            cout << "NULL";
        }

        cout << endl;
        curr = curr->next;
    }
    cout << "End list." << endl << endl;
}
