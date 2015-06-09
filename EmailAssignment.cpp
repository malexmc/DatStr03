// EmailAssignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <vector>
#include <string>

#include "Inbox.h"

int main(int argc, _TCHAR* argv[])
{
	Inbox* inbox = new Inbox();

	/*inbox->PrintLinkedList();
	inbox->DeleteCommunication("a");
	inbox->PrintLinkedList();
	inbox->InsertEmail("b");
	inbox->PrintLinkedList();
	inbox->DeleteCommunication("a");
	inbox->PrintLinkedList();
	inbox->InsertEmail("a");
	inbox->PrintLinkedList();
	inbox->DeleteCommunication("b");
	inbox->PrintLinkedList();
	inbox->InsertEmail("b");
	inbox->InsertEmail("c");
	inbox->InsertEmail("d");
	inbox->PrintLinkedList();
	inbox->DeleteCommunication("c");
	inbox->PrintLinkedList();
	inbox->DeleteCommunication("a");
	inbox->PrintLinkedList();
	return 0;*/

	string subjects[] = 
	{
		"a",
		"b",
		"b",
		"c",
		"b",
		"d",
		"a"
	};
	int length = sizeof(subjects) / sizeof(string);

	for (int ii = 0; ii < length; ii++)
	{
		inbox->InsertEmail(subjects[ii]);
		//inbox->PrintLinkedList();
	}

	inbox->DeleteCommunication("b");
	//inbox->PrintLinkedList();

	inbox->PrintLinkedList();

	Inbox* copiedInbox = new Inbox(*inbox);
	copiedInbox->PrintLinkedList();

	copiedInbox->DeleteCommunication("a");
	inbox->InsertEmail("e");
	inbox->InsertEmail("c");
	copiedInbox->PrintLinkedList();
	inbox->PrintLinkedList();

	delete inbox;
	inbox = 0;
	return 0;
}

