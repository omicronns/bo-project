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

double Point::getX() {
    return x;
}

double Point::getY() {
    return y;
}

double Point::distanceSqr(Point pt) {
    return (x - pt.x) * (x - pt.x) + (y - pt.y) * (y - pt.y);
}
