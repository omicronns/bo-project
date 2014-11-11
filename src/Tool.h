/*
 * Tool.h
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#ifndef TOOL_H_
#define TOOL_H_

#include <string>

class Tool {
    std::string name;
    int id;

public:
    Tool(int id, std::string toolName);
    int getToolId() const;
    std::string getToolName() const;
    bool operator==(const Tool &tool) const;
    bool operator!=(const Tool &tool) const;
};

#endif /* TOOL_H_ */
