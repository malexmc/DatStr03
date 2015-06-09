#include <iostream>
#include <string>
using namespace std;
#ifndef EMAILLIST_H
#define EMAILLIST_H

struct email{
  string to;
  string from;
  string message;
};

struct emailnode{
    emailnode* prev;
    emailnode* next;
    string subject;    
    email* emailHead;
    unsigned int quantity;
};



class EmailList(){
public:
  EmailList();
  ~EmailList();  

  void Insert();
  void Delete();
  

private:
  email* head;
  email* tail;
  unsigned int size;
};

#endif //EMAILLIST_H
