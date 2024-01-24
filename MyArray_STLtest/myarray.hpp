#include <iostream>

using namespace std;

template <class T>
class MyArray
{
public:
    typedef T* iterator;

    MyArray(int tCapacity = 10)
    {
        capacity = tCapacity;
        size = 0;
        data = new T[capacity];
    }

    void push_back(T data)
    {
        if(size != capacity)
        {
            this->data[size++] = data;
        }
    }

    T* begin()
    {
        return data;
    }

    T* end()
    {
        return data + size;
    }

    ~MyArray()
    {
        if(data != NULL)
        {
            delete[] data;
            data = NULL;
            capacity = 0;
            size = 0;
        }
    }

private:
    T* data;
    int size;
    int capacity;
};

