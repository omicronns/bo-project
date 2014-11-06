/*
 * Point.h
 *
 *  Created on: 5 Nov 2014
 *      Author: adasubu
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
	double xv;
	double yv;
public:
	Point(double x = 0, double y = 0) :
			xv(x), yv(y) {
	}

	double x() {
		return xv;
	}

	double y() {
		return yv;
	}

	double distanceSqr(Point pt) {
		return (xv - pt.xv) * (xv - pt.xv) + (yv - pt.yv) * (yv - pt.yv);
	}
};

#endif /* POINT_H_ */
