#include <iostream>

#include "contact.h"

using namespace std;

int main()
{
    Contact* con;
    con = new Contact;
    con->name = "Bob";
    con->next = new Contact;
    con->next->name = "hhe";
    cout << con->name << endl;
    cout << con->next->name << endl;
    con->name = con->next->name;
    cout << con->name << endl;
    con->name = con->name + con->next->name;
    cout << con->name << endl;
    return 0;
}