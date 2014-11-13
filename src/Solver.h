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
    friend std::ostream &operator<<(std::ostream & str, const Solver &solver);

    Problem problem;
    std::vector<int> solution;

public:
    Solver(Problem problem);
    double calcCost() const;
    void permuteSolution(int iterations);
    double solve(double temp,
                 double stopTemp,
                 double alpha,
                 double beta,
                 double gamma,
                 int itersPerTemp,
                 std::list<double> &costs);
    std::vector<int> getSolution() const;
};

std::ostream &operator<<(std::ostream & str, const Solver &solver);

#endif /* SOLVER_H_ */
