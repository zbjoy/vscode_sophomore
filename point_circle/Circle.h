#pragma once
#include <iostream>
#include "Point.h"

using namespace std;

class Circle
{
public:
    void setInformation(int x, int y, double r);
    double getLength(Point p);

private:
    Point pointHeader;
    double r;
};