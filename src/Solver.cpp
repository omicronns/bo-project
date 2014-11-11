/*
 * Solver.cpp
 *
 *  Created on: 5 Nov 2014
 *      Author: adasubu
 */

#include "Solver.h"
#include "Random.h"

Solver::Solver(Problem problem)
        : problem(problem){
    std::vector<Workpoint> workpoints = problem.getWorkpoints();
    Random rand;
    while(workpoints.size() != 0) {
        int n = rand.randi(0, workpoints.size() - 1);
        workpoints[n].popTool();
        solution.push_back(workpoints[n].getN());
        if(workpoints[n].getToolsCount() == 0) {
            std::vector<Workpoint>::iterator it = workpoints.begin();
            while(n--)
                ++it;
            workpoints.erase(it);
        }
    }
}

std::vector<int> Solver::getSolution() {
    return solution;
}

Problem Solver::getProblem() {
    return problem;
}
