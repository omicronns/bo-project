/*
 * Problem.cpp
 *
 *  Created on: 6 Nov 2014
 *      Author: adasubu
 */

#include <iostream>
#include <sstream>
#include "Problem.h"
#include "Toolchain.h"


Problem::Problem() {
}

Problem::Problem(Toolchain toolchain)
        : toolchain(toolchain) {
}

Problem::Problem(int workpointsCount, int maxtools, Toolchain toolchain, double maxX, double maxY)
        : toolchain(toolchain) {
    Random rand;
    for(int i = 0; i < workpointsCount; ++i) {
        workpoints.push_back(Workpoint(i, Point(rand.randf(0, maxX), rand.randf(0, maxY))));
        for(int j = 0, tools = rand.randi(1, maxtools), toolCount = toolchain.getToolsCount(); j < tools; ++j) {
            workpoints.back().pushTool(rand.randi(0, toolCount - 1));
        }
    }
}

void Problem::setToolchain(Toolchain toolchain) {
    this->toolchain = toolchain;
}

Toolchain Problem::getToolchain() const {
    return toolchain;
}

std::vector<Workpoint> Problem::getWorkpoints() const {
    return workpoints;
}

std::ostream &operator<<(std::ostream & str, const Problem &problem) {
    str << "> > > > problem begin\n";
    for(std::vector<Workpoint>::const_iterator it = problem.workpoints.begin(); it != problem.workpoints.end(); ++it) {
        str << *it << "\n";
    }
    return str << "> > > > problem end\n";
}

std::istream &operator>>(std::istream & str, Problem &problem) {
    std::string prologue;
    std::getline(str, prologue);
    if(prologue != "> > > > problem begin") {
        std::cerr << "wrong prologue, problem corrupted\n";
        return str;
    }
    std::string line;
    std::getline(str, line);
    problem.workpoints.clear();
    while(line != "> > > > problem end") {
        Workpoint wp;
        std::istringstream lineStream;
        lineStream.str(line);
        lineStream >> wp;
        problem.workpoints.push_back(wp);
        std::getline(str, line);
    }
    return str;
}
