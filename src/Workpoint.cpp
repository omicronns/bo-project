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

Workpoint::Workpoint(int n, Point pt) :
        n(n), pt(pt) {
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
    }
    else {
        std::cerr << "[err: trying to access a tool from an empty workpoint toollist]\n";
        return -1;
    }
}

std::list<int> Workpoint::getToolSequence() const {
    return toolSequence;
}

int Workpoint::popTool() {
    if(toolSequence.size() != 0) {
        int poppedTool = toolSequence.back();
        toolSequence.pop_back();
        return poppedTool;
    }
    else {
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
    std::list<int> toolList = workpoint.getToolSequence();
    if(toolList.size() != 0) {
        while(toolList.size() != 0) {
            str << std::setw(3) << toolList.back();
            toolList.pop_back();
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
    Workpoint wp(n, pt);
    while(lineStream >> tool) {
        wp.pushTool(tool);
    }
    workpoint = wp;
    return str;
}
