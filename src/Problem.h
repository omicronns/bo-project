/*
 * Problem.h
 *
 *  Created on: 6 Nov 2014
 *      Author: adasubu
 */

#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <vector>

#include "Toolchain.h"
#include "Workpoint.h"
#include "Random.h"

class Problem {
    int workpointsCount;
    Toolchain toolchain;
	std::vector<Workpoint> workpoints;

public:
    Problem(int workpointsCount, int maxtools, Toolchain toolchain);
    Problem(std::vector<Workpoint> workpoints, Toolchain toolchain);
    Toolchain getToolchain() const;
    std::vector<Workpoint> getWorkpoints() const;
};

std::ostream &operator<<(std::ostream & str, const Problem &problem);

#endif /* PROBLEM_H_ */
