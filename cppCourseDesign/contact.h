#pragma once

#include <iostream>
#include <string.h>
#include "mString.h"

using namespace std;

class Contact
{
public:

    Contact();

    int num;
    my_String name;
    int age;
    my_String tele;
    my_String addr;
    Contact* next;
    
private:

};