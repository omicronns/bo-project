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
    Workpoint(int n, Point pt);
    Point getPoint() const;
    int getN() const;
    int getToolsCount() const;
    int getNextTool() const;
    std::list<int> getToolSequence() const;
    int popTool();
    void pushTool(int toolId);
};

std::ostream &operator<<(std::ostream & str, const Workpoint &workpoint);

#endif /* WORKPOINT_H_ */
