/*
 * Problem.h
 *
 *  Created on: 6 Nov 2014
 *      Author: adasubu
 */

#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <iostream>
#include <random>
#include <string>
#include <vector>

#include "Point.h"
#include "Tools.h"



class Problem {
	std::vector<Workpoint> workpoints;

public:
	void generateProblem(int workpoints, int maxtools, ToolChain toolchain);
};

#endif /* PROBLEM_H_ */
