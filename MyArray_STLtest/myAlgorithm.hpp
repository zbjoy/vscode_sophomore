#include <iostream>

using namespace std;

template <typename T>
void for_earch(T* begin, T* end, void (*func)(T&))
{
    if(begin > end)
    {
        return;
    }

    while(begin != end)
    {
        func(*begin);
        ++begin;
    }
}