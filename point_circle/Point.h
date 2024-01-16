#pragma once

#include <iostream>

using namespace std;

class Point
{
public:

    void setPoint(int x, int y);
    double getLength(Point temp);

private:

    int x;
    int y;
};

double myPow(double num, int x);