/*
 * Workpoint.cpp
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#include <iomanip>
#include <iostream>
#include <sstream>
#include "Workpoint.h"

Workpoint::Workpoint(int n, Point pt)
        : n(n), pt(pt) {
}

Point Workpoint::getPoint() const {
    return pt;
}

int Workpoint::getN() const {
    return n;
}

int Workpoint::getToolsCount() const {
    return toolSequence.size();
}

int Workpoint::getNextTool() const {
    if(toolSequence.size() != 0) {
        return toolSequence.front();
    } else {
        std::cerr << "[err: trying to access a tool from an empty workpoint toollist]\n";
        return -1;
    }
}

int Workpoint::popTool() {
    if(toolSequence.size() != 0) {
        int poppedTool = toolSequence.back();
        toolSequence.pop_back();
        return poppedTool;
    } else {
        std::cerr << "[err: trying to pop a tool from an empty workpoint toollist]\n";
        return -1;
    }
}

void Workpoint::pushTool(int toolId) {
    toolSequence.push_front(toolId);
}

std::ostream &operator<<(std::ostream & str, const Workpoint &workpoint) {
    str << std::setw(4) << workpoint.getN() << "\t";
    str << workpoint.getPoint() << "\t";

    if(workpoint.toolSequence.size() != 0) {
        for(std::list<int>::const_iterator it = workpoint.toolSequence.begin(); it != workpoint.toolSequence.end();
                ++it) {
            str << std::setw(3) << *it;
        }
    }
    return str;
}

std::istream &operator>>(std::istream & str, Workpoint &workpoint) {
    std::istringstream lineStream;
    std::string line;
    std::getline(str, line);
    lineStream.str(line);
    int n, tool;
    Point pt;
    lineStream >> n >> pt;
    workpoint.n = n;
    workpoint.pt = pt;
    workpoint.toolSequence.clear();
    while(lineStream >> tool) {
        workpoint.pushTool(tool);
    }
    return str;
}

int Workpoint::getLastTool() const {
    if(toolSequence.size() != 0) {
        return toolSequence.back();
    } else {
        std::cerr << "[err: trying to access a tool from an empty workpoint toollist]\n";
        return -1;
    }
}
