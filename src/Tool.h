/*
 * Tool.h
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#ifndef TOOL_H_
#define TOOL_H_

#include <string>
#include <iostream>

class Tool {
    std::string name;
    int id;
    double cost;

public:
    Tool(int id, std::string name, double cost = 0.0);
    std::string getToolName() const;
    int getToolId() const;
    double getToolCost() const;
    bool operator==(const Tool &tool) const;
    bool operator!=(const Tool &tool) const;
};

std::ostream &operator<<(std::ostream &str, const Tool &tool);

#endif /* TOOL_H_ */
