/*
 * Toolchain.h
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#ifndef TOOLCHAIN_H_
#define TOOLCHAIN_H_

#include <stdexcept>
#include <vector>
#include "Tool.h"

class Toolchain {
    int toolCount;
    std::vector<Tool> toolChain;

public:
    Toolchain();
    int addTool(std::string toolName);
    int getToolsCount() const;
    int getToolId(std::string toolName) const;
    std::string getToolName(int toolId) const;
};

#endif /* TOOLCHAIN_H_ */
