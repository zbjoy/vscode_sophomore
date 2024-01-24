#include <iostream>
#include "myAlgorithm.hpp"
#include "myarray.hpp"
//#include <algorithm>
using namespace std;

void print_int(int& data)
{
    cout << data << " ";
}

class Maker;
void print_Maker(Maker& data);

class Maker
{
    friend void print_Maker(Maker& data);
public:
    Maker(){};
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }

    Maker(const Maker& maker)
    {
        name = maker.name;
        age = maker.age;
    }

    

private:
    string name;
    int age;
};

void print_Maker(Maker& data)
{
    cout << "Name: " << data.name << " Age: " << data.age << endl; 
}

void test()
{
    MyArray<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);

    MyArray<int>::iterator begin = arr.begin();
    MyArray<int>::iterator end = arr.end();

    for_earch(begin, end, print_int);
    cout << endl;
}

void test02()
{
    MyArray<Maker> arr;
    arr.push_back(Maker("Tom1", 12));
    arr.push_back(Maker("Tom2", 22));
    arr.push_back(Maker("Tom3", 32));
    arr.push_back(Maker("Tom4", 42));
    arr.push_back(Maker("Tom5", 52));

    MyArray<Maker>::iterator begin = arr.begin();
    MyArray<Maker>::iterator end = arr.end();

    for_earch(begin, end, print_Maker);
}

int main()
{
    //test();
    test02();
    return 0;
}