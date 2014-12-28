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
    friend std::ostream &operator<<(std::ostream & str, const Workpoint &workpoint);
    friend std::istream &operator>>(std::istream & str, Workpoint &workpoint);

    int n;
    Point pt;
    std::list<int> toolSequence;

public:
    Workpoint() = default;
    Workpoint(int n, Point pt);
    Point getPoint() const;
    int getN() const;
    int getToolsCount() const;
    int getNextTool() const;
    int popTool();
    void pushTool(int toolId);

    int getLastTool() const;
};

std::ostream &operator<<(std::ostream & str, const Workpoint &workpoint);
std::istream &operator>>(std::istream & str, Workpoint &workpoint);

#endif /* WORKPOINT_H_ */
