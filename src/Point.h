/*
 * Point.h
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#ifndef POINT_H_
#define POINT_H_

#include <iostream>

class Point {
    double x;
    double y;

public:
    Point(double x = 0, double y = 0);
    double getX() const;
    double getY() const;
    double distanceSqr(Point pt) const;
};

std::ostream &operator<<(std::ostream & str, const Point &pt);

#endif /* POINT_H_ */
