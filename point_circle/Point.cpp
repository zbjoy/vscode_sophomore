#include "Point.h"

double myPow(double num, int x)
{
    if(x == 0)
    return 0.0;
    double temp = num;

    while(--x)
    {
        num *= temp;
    }
    return num;
}

void Point::setPoint(int x, int y)
{
    this->x = x;
    this->y = y;
}

double Point::getLength(Point temp)
{
    return (myPow(temp.x, 2) + myPow(temp.y, 2));
}
