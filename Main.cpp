#include <iostream>
#include "Inbox.cpp"

using namespace std;

int main(){
    Inbox myInbox = Inbox();
    string a = "a";
    string b = "b";
    string c = "c";
    myInbox.InsertComm(c);
    myInbox.InsertComm(b);
    myInbox.InsertComm(a);
    myInbox.InsertComm(c);
    myInbox.InsertComm(c);
    myInbox.DisplayInbox();
    cout << "Done.";
    
    return 1;
}
