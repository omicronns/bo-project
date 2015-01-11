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
    friend std::ostream &operator<<(std::ostream & str, const Problem &problem);
    friend std::istream &operator>>(std::istream & str, Problem &problem);

    Toolchain toolchain;
    std::vector<Workpoint> workpoints;

public:
    Problem();
    Problem(Toolchain toolchain);
    Problem(int workpointsCount, int maxtools, Toolchain toolchain, double maxX = 1.0, double maxY = 1.0);
    void setToolchain(Toolchain toolchain);
    Toolchain getToolchain() const;
    std::vector<Workpoint> getWorkpoints() const;
};

std::ostream &operator<<(std::ostream & str, const Problem &problem);
std::istream &operator>>(std::istream & str, Problem &problem);

#endif /* PROBLEM_H_ */
