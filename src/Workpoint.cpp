/*
 * Workpoint.cpp
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#include <iostream>
#include "Workpoint.h"

Workpoint::Workpoint(int n, double x, double y) :
        n(n), pt(Point(x, y)) {
}

int Workpoint::toolsCount() {
    return toolSequence.size();
}

void Workpoint::pushTool(int toolId) {
    toolSequence.push_back(toolId);
}

int Workpoint::popTool() {
    if(toolSequence.size() != 0) {
        int poppedTool = toolSequence.front();
        toolSequence.pop_front();
        return poppedTool;
    }
    else {
        std::cerr << "[err: trying to pop a tool from an empty workpoint toollist]";
        return -1;
    }
}
