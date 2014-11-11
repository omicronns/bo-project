/*
 * Tool.cpp
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#include "Tool.h"

Tool::Tool(int id, std::string name) :
        name(name), id(id) {
}

std::string Tool::getToolName() const {
    return name;
}

int Tool::getToolId() const {
    return id;
}

bool Tool::operator==(const Tool &tool) const {
    return id == tool.id;
}

bool Tool::operator!=(const Tool &tool) const {
    return id != tool.id;
}

std::ostream &operator<<(std::ostream & str, const Tool &tool) {
    return str << "[" << tool.getToolId() << ":" << tool.getToolName() << "]";
}
