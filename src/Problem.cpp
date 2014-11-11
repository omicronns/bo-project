/*
 * Problem.cpp
 *
 *  Created on: 6 Nov 2014
 *      Author: adasubu
 */

#include <iostream>
#include "Problem.h"
#include "Toolchain.h"

Problem::Problem(int workpointsCount, int maxtools, Toolchain toolchain)
        : workpointsCount(workpointsCount), toolchain(toolchain) {
    Random rand;
    for(int i = 0; i < workpointsCount; ++i) {
        workpoints.push_back(Workpoint(i, Point(rand.randf(), rand.randf())));
        for(int j = 0, tools = rand.randi(1, maxtools), toolCount = toolchain.getToolsCount(); j < tools; ++j) {
            workpoints.back().pushTool(rand.randi(0, toolCount - 1));
        }
    }
}

Problem::Problem(std::vector<Workpoint> workpoints, Toolchain toolchain)
        : toolchain(toolchain), workpoints(workpoints) {
}

Toolchain Problem::getToolchain() const {
    return toolchain;
}

std::vector<Workpoint> Problem::getWorkpoints() const {
    return workpoints;
}

std::ostream &operator<<(std::ostream & str, const Problem &problem) {
    std::vector<Workpoint> workpoints = problem.getWorkpoints();
    str << "> > > > problem begin\n";
    for(std::vector<Workpoint>::const_iterator it = workpoints.begin(); it != workpoints.end(); ++it) {
        str << *it << "\n";
    }
    return str << "> > > > problem end\n";
}
