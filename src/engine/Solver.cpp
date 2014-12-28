/*
 * Solver.cpp
 *
 *  Created on: 5 Nov 2014
 *      Author: adasubu
 */

#include "Solver.h"
#include "Random.h"
#include "temperaturedata.h"

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

std::vector<int> Solver::getSolution() const {
    return solution;
}

double Solver::calcCost() const {
    Point lastPoint = Point();
    double cost = 0.0;
    std::vector<Workpoint> workpoints = problem.getWorkpoints();
    Toolchain toolchain = problem.getToolchain();
    int lastTool = -1;
    for(std::vector<int>::const_iterator it = solution.begin(); it != solution.end(); ++it) {
        cost += lastPoint.distanceSqr(workpoints[*it].getPoint());
        int tool = workpoints[*it].popTool();
        if(tool != lastTool) {
            cost += toolchain.getTool(tool).getToolCost();
            cost += lastPoint.distanceSqr(Point()) + workpoints[*it].getPoint().distanceSqr(Point());
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

double Solver::solve(double temp,
                     double stopTemp,
                     double alpha,
                     double beta,
                     double gamma,
                     int itersPerTemp,
                     std::list<double> &costs) {
    Random rand;
    double bestCost = calcCost();
    std::vector<int> bestSolution = solution;

    //dodane
    GUIDataObject.clear(GUIData::temperatureEnum);

    while(temp > stopTemp) {
        for(int i = 0; i < itersPerTemp; ++i) {
            permuteSolution(temp * gamma + 1);
            double cost = calcCost();
            if(cost < bestCost) {
                costs.push_back(cost);
                bestCost = cost;
                bestSolution = solution;

                //dodane
                GUIDataObject.temperature_pushBack(temp);

            } else {
                if(rand.randf() < std::exp(((bestCost - cost) * beta) / temp)) {
                    costs.push_back(cost);

                    //dodane
                    GUIDataObject.temperature_pushBack(temp);

                    bestCost = cost;
                    bestSolution = solution;
                } else {
                    solution = bestSolution;
                }
            }
        }
        temp *= alpha;
    }
    return bestCost;
}

std::ostream &operator<<(std::ostream & str, const Solver &solver) {
    Toolchain tlc = solver.problem.getToolchain();
    std::vector<Workpoint> workpoints = solver.problem.getWorkpoints();

    str << "> > > > solution begin\n";
    for(std::vector<int>::const_iterator it = solver.solution.begin(); it != solver.solution.end(); ++it) {
        str << *it << "\t" << tlc.getToolName(workpoints[*it].popTool()) << "\n";
    }
    return str << "> > > > solution end\n";
}
