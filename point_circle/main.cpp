#include <iostream>
#include "Point.h"
#include "Circle.h"

using namespace std;

int main()
{
    Point a;
    a.setPoint(0, 0);
    Circle c;
    c.setInformation(1, 1, 1.0);
    cout << c.getLength(a);
    return 0;
}