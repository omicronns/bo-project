/*
 * Point.cpp
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#include "Point.h"


Point::Point(double x, double y) :
        x(x), y(y) {
}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::distanceSqr(Point pt) const {
    return (x - pt.x) * (x - pt.x) + (y - pt.y) * (y - pt.y);
}

std::ostream &operator<<(std::ostream & str, const Point &pt) {
    return str << "(" << pt.getX() << ", " << pt.getY() << ")";
}
