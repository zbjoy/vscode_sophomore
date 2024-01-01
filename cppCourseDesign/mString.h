#pragma once
#include <iostream>
#include <string.h>

using namespace std;


class my_String
{
    friend ostream &operator<<(ostream &cout, my_String& str);
public:
    my_String();
    my_String(const char* str);

    my_String& operator=(const my_String& str);
    my_String& operator=(const char* str);
    my_String& operator+(my_String& str);
    my_String& operator+(const char* str);

    char* getData();

    bool operator==(const my_String& str);

    char& operator[](int index)
    {
        return this->data[index];
    }

    ~my_String();

private:

    void my_String_Delete(my_String& str);

    void my_StrCopy(const my_String& src);
    void my_StrCopy(const char* src);

private:
    char* data;
    int capacity;
    int size;
};

ostream& operator<<(ostream& cout, my_String& str);