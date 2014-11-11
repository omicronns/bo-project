/*
 * Workpoint.cpp
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#include <iomanip>
#include <iostream>
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
    toolSequence.push_back(toolId);
}

std::ostream &operator<<(std::ostream & str, const Workpoint &workpoint) {
    str << "{";
    str << std::setw(3) << workpoint.getN();
    str << " ; (";
    str << std::setw(12) << std::setprecision(6) << workpoint.getPoint().getX();
    str << ", ";
    str << std::setw(12) << std::setprecision(6) << workpoint.getPoint().getY();
    str << ") ; ";
    std::list<int> toolList = workpoint.getToolSequence();
    if(toolList.size() != 0) {
        while(toolList.size() > 1) {
            str << std::setw(2) << toolList.back();
            str << "->";
            toolList.pop_back();
        }
        str << std::setw(2) << toolList.back();
    }
    else {
        str << std::setw(2) << "--";
    }
    return str << " }";
}
