#include "Circle.h"

void Circle::setInformation(int x, int y, double r)
{
    pointHeader.setPoint(x, y);
    this->r = r;
}

double Circle::getLength(Point p)
{
    return (p.getLength(this->pointHeader));
}
