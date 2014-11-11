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

int Toolchain::addTool(std::string toolName) {
    if(getToolId(toolName) == -1) {
        toolChain.push_back(Tool(toolCount++, toolName));
        return toolChain.back().getToolId();
    }
    return -1;
}

int Toolchain::getToolsCount() const {
    return toolCount;
}

int Toolchain::getToolId(std::string toolName) const {
    if(!toolChain.empty()) {
        for(std::vector<Tool>::const_iterator it = toolChain.begin(); it != toolChain.end(); ++it) {
            if(it->getToolName() == toolName)
                return it->getToolId();
        }
    }
    return -1;
}

std::string Toolchain::getToolName(int toolId) const {
    try {
        return toolChain.at(toolId).getToolName();
    }
    catch(std::out_of_range &e) {
        return "[err: trying to access tool at index outside toolchain]";
    }
}
