/*
Authors: William Hauber
John Mikolay
Matthew McClellan
Course Title: Data Structures
Course Number: CS2028
Instructor: Anca Ralescu
TA: Suryadip Chakraborty
Abstract: Assignment 3 Main.cpp uses the Inbox class to create a linked list of emails grouped
by subject name. It supports inserting, deleting, and searching for emails by subject name. To use the program
start it in terminal. Then insert an email by typing the subject name followed by enter. When finished inserting
type "done" and the inbox will be displayed.
Preconditions:
Postconditions:
Credits:
Dr. Paul Talaga for his life-saving Makefile
*/


//#include "stdafx.h"

#include <iostream>
#include "Inbox.h"

using namespace std;

int main(){
    Inbox* myInbox =  new Inbox();
    
    // Take in emails from command line, stop when "done" is entered.
    while( true )
    {
        string emailSubject;
        getline( cin, emailSubject );
        if( emailSubject == "done" )
            break;
        myInbox->InsertEmail(emailSubject);
    }
    
    myInbox->DisplayInbox();
    delete myInbox;
    return 1;
}
