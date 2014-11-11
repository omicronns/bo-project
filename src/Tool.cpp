/*
 * Tool.cpp
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#include "Tool.h"

Tool::Tool(int id, std::string toolName) :
        name(toolName), id(id) {
}

int Tool::getToolId() const {
    return id;
}

std::string Tool::getToolName() const {
    return name;
}

bool Tool::operator==(const Tool &tool) const {
    return id == tool.id;
}

bool Tool::operator!=(const Tool &tool) const {
    return id != tool.id;
}
