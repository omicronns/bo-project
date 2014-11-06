/*
 * Tools.h
 *
 *  Created on: 6 Nov 2014
 *      Author: adasubu
 */

#ifndef TOOLS_H_
#define TOOLS_H_

#include <string>
#include <vector>

class Tool {
	std::string toolName;
	int id;

public:
	Tool(int id, std::string toolName) :
			toolName(toolName), id(id) {
	}

	int getToolId() {
		return id;
	}

	std::string getToolName() {
		return toolName;
	}

	bool operator==(const Tool &tool) const {
		return id == tool.id;
	}

	bool operator!=(const Tool &tool) const {
		return id != tool.id;
	}
};



class ToolChain {
	int toolCount;
	std::vector<Tool> toolChain;

public:
	ToolChain() :
			toolCount(0) {
	}

	int getToolsCount() {
		return toolCount;
	}

	int addTool(std::string toolName) {
		if(getToolId(toolName) == -1) {
			toolChain.push_back(Tool(toolCount++, toolName));
			return toolChain.back().getToolId();
		}
		return -1;
	}

	int getToolId(std::string toolName) {
		if(!toolChain.empty()) {
			for(std::vector<Tool>::iterator it = toolChain.begin(); it != toolChain.end(); ++it) {
				if(it->getToolName() == toolName)
					return it->getToolId();
			}
		}
		return -1;
	}

	std::string getToolName(int toolId) {
		if(toolId >= 0 && toolId < (int)toolChain.size()) {
			return toolChain[toolId].getToolName();
		}
		else {
			return "[err: trying to access tool at index outside toolChain]";
		}
	}
};

#endif /* TOOLS_H_ */
