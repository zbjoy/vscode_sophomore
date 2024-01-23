#include <iostream>
#include <string>
#include "myArray.hpp"

using namespace std;

void test()
{
    MyArray<string> arr;
    string a1("aaa");
    string a2("bbb");
    string a3("ccc");
    string a4("ddd");
    string a5("eee");

    arr.push_Back(a1);
    arr.push_Back(a2);
    arr.push_Back(a3);
    arr.push_Back(a4);
    arr.push_Back(a5);

    for(int i =0; i < 5; i++)
    {
        try
        {
            cout << arr[i] << " ";
        }
        catch(out_of_range& err)
        {
            //std::cerr << e.what() << '\n';
            cout << err.what() << endl;
        }
        

    }

}

int main()
{
    test();
    return 0;
}