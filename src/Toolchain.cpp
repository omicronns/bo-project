/*
 * Toolchain.cpp
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#include "Toolchain.h"


Toolchain::Toolchain() :
        toolCount(0) {
}

int Toolchain::addTool(std::string name, double cost) {
    if(getToolId(name) == -1) {
        toolChain.push_back(Tool(toolCount++, name, cost));
        return toolChain.back().getToolId();
    }
    return -1;
}

int Toolchain::getToolsCount() const {
    return toolCount;
}

int Toolchain::getToolId(std::string name) const {
    if(!toolChain.empty()) {
        for(std::vector<Tool>::const_iterator it = toolChain.begin(); it != toolChain.end(); ++it) {
            if(it->getToolName() == name)
                return it->getToolId();
        }
    }
    return -1;
}

std::string Toolchain::getToolName(int id) const {
    try {
        return toolChain.at(id).getToolName();
    }
    catch(std::out_of_range &e) {
        return "[err: trying to access tool at index outside toolchain]";
    }
}

Tool Toolchain::getTool(std::string name) const {
    return toolChain[getToolId(name)];
}

Tool Toolchain::getTool(int id) const {
    return toolChain[id];
}

std::ostream &operator<<(std::ostream & str, const Toolchain &toolchain) {
    str << "> > > > toolchain begin\n";
    for(int i = 0; i < toolchain.getToolsCount(); ++i) {
        str << toolchain.getTool(i) << "\n";
    }
    str << "> > > > toolchain end\n";
    return str;
}
