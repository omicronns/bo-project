/*
 * Toolchain.h
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#ifndef TOOLCHAIN_H_
#define TOOLCHAIN_H_

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Tool.h"

class Toolchain {
    int toolCount;
    std::vector<Tool> toolChain;

public:
    Toolchain();
    int addTool(std::string name);
    int getToolsCount() const;
    int getToolId(std::string name) const;
    std::string getToolName(int id) const;
    Tool getTool(std::string name) const;
    Tool getTool(int id) const;
};

std::ostream &operator<<(std::ostream &str, const Toolchain &toolchain);

#endif /* TOOLCHAIN_H_ */
