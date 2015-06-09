#include <iostream>
#include <string>
#include "EmailList.h"

using namespace std;

//constructor
EmailList::EmailList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

//destructor
EmailList::~EmailList(){
    while(head){
        delete head->prev;
        emailnode* temp = head->next;
        delete head->next;
        head = temp;
    }
    delete head;
    delete tail;

}

//Insert a node into the EmailList
EmailList::Insert(){


}


//Delete a node from the EmailList
EmailList::Delete(){

}
