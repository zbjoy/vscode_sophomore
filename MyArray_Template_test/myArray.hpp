#include <iostream>

using namespace std;

template <class T>
class MyArray
{
public:
    MyArray()
    {
        capacity = 5;
        size = 0;
        data = new T[capacity];
    }

    MyArray(const MyArray& d);
    T& operator[](int index);
    T& operator=(T& d);
    void pop_Back();
    void push_Back(T d);

    ~MyArray()
    {
        if(data != NULL)
        {
            delete[] data;
            data = NULL;
        }
    }

private:
    T* data;
    int size;
    int capacity;
};

template <class T>
MyArray<T>::MyArray(const MyArray& d)
{
    this->capacity = d.capacity;
    this->size = d.size;
    data = new T[capacity];
    for(int i = 0; i < size; i++)
    {
        data[i] = d.data[i];
    }
}

template <class T>
T& MyArray<T>::operator[](int index)
{
    if(index < 0 || index > size)
    {
        throw out_of_range("error");
    }

    if(index == size)
    {
        if(size == capacity)
        {
            throw out_of_range("error");
        }
        size++;
    }

    return data[index];
}

template <class T>
T& MyArray<T>::operator=(T& d)
{
    if(this->data != NULL)
    {
        delete[] data;
        data = NULL;
    }

    this->capacity = d.capacity;
    this->size = d.size;
    data = new T[capacity];
    for(int i = 0; i < size; i++)
    {
        data[i] = d.data[i];
    }
}

template <class T>
void MyArray<T>::pop_Back()
{
    if(size > 0)
    {
        size--;
    }
}

template <class T>
void MyArray<T>::push_Back(T d)
{
    if(size != capacity)
    {
        data[size++] = d;
    }
}