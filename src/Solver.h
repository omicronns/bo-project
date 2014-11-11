/*
 * Solver.h
 *
 *  Created on: 5 Nov 2014
 *      Author: adasubu
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include <vector>

#include "Problem.h"

class Solver {
    Problem problem;
    std::vector<int> solution;

public:
    Solver(Problem problem);
    std::vector<int> getSolution();
    Problem getProblem();
    double calcCost();
    void permuteSolution(int iterations);
    double solve(int iterations);
};

#endif /* SOLVER_H_ */
