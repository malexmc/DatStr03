#ifndef EMAILLIST_H
#define EMAILLIST_H

#include <string>
using namespace std;

// <will>
// I removed the Email struct and put its contents directly into EmailNode. I also renamed EmailNode to become PascalCased. 
// Finally, I removed the subject and quantity fields, as these values are common to all emails in the given list.
struct EmailNode {
    EmailNode* prev;
    EmailNode* next;
    string to;
	string from;
	string message;
};

class EmailList {
public:
	EmailList(string);
	EmailList(const EmailList&);
	~EmailList();  

	// <will>
	// Added EmailNode* parameters to the first method. I also update the signatures in the .cpp file.
	void Insert(EmailNode* node);
	void Delete( EmailNode* node );

private:
	EmailNode* head;
	EmailNode* tail;

	unsigned int size;
	
	// <will>
	// Added subject field. I moved this from the node objects to here.
	string subject;
};

#endif //EMAILLIST_H
