/*
 * Solver.cpp
 *
 *  Created on: 5 Nov 2014
 *      Author: adasubu
 */

#include "Solver.h"
#include "Random.h"

Solver::Solver(Problem problem)
        : problem(problem) {
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

double Solver::calcCost() {
    Point lastPoint = Point();
    double cost = 0.0;
    std::vector<Workpoint> workpoints = problem.getWorkpoints();
    Toolchain toolchain = problem.getToolchain();
    int lastTool = -1;
    for(std::vector<int>::iterator it = solution.begin(); it != solution.end(); ++it) {
        cost += lastPoint.distanceSqr(workpoints[*it].getPoint());
        int tool = workpoints[*it].popTool();
        if(tool != lastTool) {
            cost += toolchain.getTool(tool).getToolCost();
            cost += lastPoint.distanceSqr(Point()) + workpoints[*it].getPoint().distanceSqr(Point());
//            std::cout << lastTool << "->" << tool << "\n";
            lastTool = tool;
        }
        lastPoint = workpoints[*it].getPoint();
    }
    return cost;
}

void Solver::permuteSolution(int iterations) {
    Random rand;
    while(iterations--) {
        int i = rand.randi(0, solution.size() - 1);
        int j = rand.randi(0, solution.size() - 1);
        int tmp = solution[i];
        solution[i] = solution[j];
        solution[j] = tmp;
    }
}

double Solver::solve(int iterations) {
    double bestCost = calcCost();
    std::vector<int> bestSolution;

    while(iterations--) {
        permuteSolution(10);
        double cost = calcCost();
        if(cost < bestCost) {
            bestCost = cost;
            bestSolution = solution;
        }
//        else {
//            solution = bestSolution;
//        }
    }
    solution = bestSolution;
    return bestCost;
}
