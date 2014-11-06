/*
 * Point.h
 *
 *  Created on: 5 Nov 2014
 *      Author: adasubu
 */

#ifndef POINT_H_
#define POINT_H_


#include <iostream>
#include <string>
#include <list>

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

class Workpoint {
	int n;
	Point pt;
	std::list<int> toolSequence;

public:
	Workpoint(int n, double x, double y) :
			n(n), pt(Point(x, y)) {
	}

	int toolsCount() {
		return toolSequence.size();
	}

	void pushTool(int toolId) {
		toolSequence.push_back(toolId);
	}

	int popTool() {
		if(toolSequence.size() != 0) {
			int poppedTool = toolSequence.front();
			toolSequence.pop_front();
			return poppedTool;
		}
		else {
			std::cerr << "[err: trying to pop a tool from an empty workpoint toollist]";
			return -1;
		}
	}
};

#endif /* POINT_H_ */
