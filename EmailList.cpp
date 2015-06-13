//#include "stdafx.h"

#include <iostream>
#include <string>
#include "EmailList.h"

using namespace std;

//constructor
EmailList::EmailList(string subject) {
    head = NULL;
    tail = NULL;
    size = 0;

	this->subject = subject;
}

EmailList::EmailList(const EmailList& other) {
	subject = other.subject;

	// <will>
	// The size will be changed during the calls to Insert() later.
	size = 0;

	// <will>
	// Since the emails are stored as a stack, we're going to start from the back of other and push
	// the emails onto the new instance in reverse order. This will actually get us the proper order.
	EmailNode* curr = other.tail;
	while (curr != 0) {
		// <will>
		// Create the new node and copy the fields from the current node.
		// Then put the new node into the new EmailList instance.
		EmailNode* newNode = new EmailNode;
		newNode->to = curr->to;
		newNode->from = curr->from;
		newNode->message = curr->message;
		Insert(newNode);

		curr = curr->prev;
	}
}

//destructor
EmailList::~EmailList() {
    while(head) {
		// <will>
		// Instead of doing any of this temp stuff, couldn't we just keep calling EmailList::Delete() on the head?
		// I'm going to leave it the way it is for now though.

        // <will>
		// I commented this out. The head's previous will always be null (unless we're going circular, which I don't think is correct),
		// so this will always be useless.
		//delete head->prev;

        EmailNode* temp = head->next;

		// <will>
		// I don't think you meant to delete "next" here; we should be deleting the current head instead.
        //delete head->next;
		delete head;

        head = temp;
    }

	// <will>
	// Shouldn't these get cleaned up in the while loop?
	//delete head;
    //delete tail;

}

// <will>
// Insert a node into the front of EmailList
void EmailList::Insert(EmailNode* node) {
	// <will>
	// If there is no tail (this is the first element), the new node is the tail.
	if (tail == 0) {
		tail = node;
	}

	// <will>
	// Place the new node in the list.
	node->prev = 0;
	node->next = head;

	// <will>
	// If there was already a head (this is not the first element), set its prev field to the new node.
	if (head != 0) {
		head->prev = node;
	}

	// <will>
	// Point the head to the new node.
	head = node;
	size++;
}


// <John> Deletes a node from the EmailList
void EmailList::Delete( EmailNode* node) {
	if (node == head){
		head = node->next;
	}
	else if (node == tail){
		tail = node->prev;
	}

	EmailNode* prevNode = node->prev;
	EmailNode* nextNode = node->next;

	if (prevNode != 0)
		prevNode->next = nextNode;

	if (nextNode != 0)
		nextNode->prev = prevNode;

	delete node;
}
