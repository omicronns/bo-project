/*
 * Workpoint.h
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#ifndef WORKPOINT_H_
#define WORKPOINT_H_

#include <list>
#include "Point.h"

class Workpoint {
    int n;
    Point pt;
    std::list<int> toolSequence;

public:
    Workpoint(int n, double x, double y);
    int toolsCount();
    int popTool();
    void pushTool(int toolId);
};

#endif /* WORKPOINT_H_ */
