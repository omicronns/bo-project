/*
 * Toolchain.h
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#ifndef TOOLCHAIN_H_
#define TOOLCHAIN_H_

#include <vector>
#include "Tool.h"

class Toolchain {
    friend std::ostream &operator<<(std::ostream &str, const Toolchain &toolchain);
    friend std::istream &operator>>(std::istream &str, Toolchain &toolchain);

    std::vector<Tool> toolChain;

public:
    Toolchain();
    int addTool(std::string name, double cost = 0.0);
    int getToolsCount() const;
    int getToolId(std::string name) const;
    std::string getToolName(int id) const;
    Tool getTool(std::string name) const;
    Tool getTool(int id) const;

    std::vector<Tool> getToolChain() const { return toolChain; }
};

std::ostream &operator<<(std::ostream &str, const Toolchain &toolchain);
std::istream &operator>>(std::istream &str, Toolchain &toolchain);

#endif /* TOOLCHAIN_H_ */
