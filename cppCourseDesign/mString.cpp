#include "mString.h"

my_String::my_String()
{
    this->size = 0;
    this->capacity = 12;
    this->data = new char[this->capacity];
    memset(this->data, 0, sizeof(char) * this->capacity);
}

my_String::my_String(const char *str)
{
    this->capacity = strlen(str) + 1;
    this->size = this->capacity;
    this->data = new char[this->capacity];
    memset(this->data, 0, sizeof(char) * this->capacity);
    
}

my_String &my_String::operator=(const my_String &str)
{
    if(str.data == NULL)
    {
        my_String_Delete(*this);
        return *this;
    }

    if(this->data != NULL)
    {
        my_String_Delete(*this);
    }

    my_StrCopy(str);

    return *this;
}

my_String &my_String::operator=(const char *str)
{
    if(str == NULL)
    {
        my_String_Delete(*this);
        return *this;
    }

    my_StrCopy(str);
    return *this;
}

my_String &my_String::operator+(my_String &str)
{
    if(str.data == NULL)
    {
        my_String_Delete(*this);
        return *this;
    }

    int tempCapacity = str.size + this->size;

    if(this->capacity < tempCapacity)
    {
        my_String temp = *this;
        my_String_Delete(*this);
        this->data = new char[tempCapacity];
        strcpy(this->data, temp.data);
    }
    strcat(this->data, str.data);
    this->size = tempCapacity - 1;
    return *this;
}

my_String &my_String::operator+(const char *str)
{
    int tempCapacity = strlen(str) + 1 + this->size;

    if(this->capacity < tempCapacity)
    {
        my_String temp = *this;
        my_String_Delete(*this);
        this->data = new char[tempCapacity];
        strcpy(this->data, temp.data);  
    }
    strcat(this->data, str);
    this->size = tempCapacity - 1;
    return *this;
}

char *my_String::getData()
{
    return this->data;
}

bool my_String::operator==(const my_String &str)
{
    if(!strcmp(str.data, this->data))
    {
        return true;
    }

    return false;
}

my_String::~my_String()
{
    my_String_Delete(*this);
}

void my_String::my_String_Delete(my_String &str)
{
    if(str.data == NULL)
    {
        return;
    }

    delete[] str.data;
    str.data = NULL;
    str.capacity = 0;
    str.size = 0;
}

void my_String::my_StrCopy(const my_String &src)
{
    if(this->data != NULL)
    {
        my_String_Delete(*this);
    }

    this->capacity = src.capacity;
    this->size = src.size;
    this->data = new char[src.capacity];
    memset(this->data, 0, sizeof(char) * this->capacity);
    for(int i = 0; i < src.size; i++)
    {
        this->data[i] = src.data[i];
    }
}

void my_String::my_StrCopy(const char *src)
{
    if(this->data != NULL)
    {
        my_String_Delete(*this);
    }


    int tempCapacity = strlen(src) + 1;
    if(this->capacity < tempCapacity)
    {
        this->capacity = tempCapacity;
        this->data = new char[this->capacity];
    }
    
    this->size = tempCapacity;
    memset(this->data, 0, sizeof(char) * this->capacity);
    for(int i = 0; i < this->size; i++)
    {
        this->data[i] = src[i];
    }
}

ostream &operator<<(ostream &cout, my_String& str)
{
    cout << str.data;
    return cout;
}
