/*
 * Problem.h
 *
 *  Created on: 6 Nov 2014
 *      Author: adasubu
 */

#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <string>
#include <vector>
#include <list>

#include "Point.h"

class Workpoint {
	int n;
	Point pt;
};

class Problem {
	std::vector<Point> points;
};

#endif /* PROBLEM_H_ */
