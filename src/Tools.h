/*
 * Tools.h
 *
 *  Created on: 6 Nov 2014
 *      Author: adasubu
 */

#ifndef TOOLS_H_
#define TOOLS_H_

#include <string>
#include <list>

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
	std::list<Tool> toolChain;

public:
	ToolChain() :
			toolCount(0) {
	}

	int getToolsCount() {
		return toolCount;
	}

	int addTool(std::string toolName) {
		if(getToolId(toolName) == -1) {
			toolChain.push_front(Tool(toolCount++, toolName));
			return toolChain.front().getToolId();
		}
		return -1;
	}

	int getToolId(std::string toolName) {
		if(!toolChain.empty()) {
			for(std::list<Tool>::iterator it = toolChain.begin(); it != toolChain.end(); ++it) {
				if(it->getToolName() == toolName)
					return it->getToolId();
			}
		}
		return -1;
	}

	std::string getToolName(int toolId) {
		if(!toolChain.empty() && toolId >= 0 && toolId < toolCount) {
			std::list<Tool>::iterator it = toolChain.begin();
			while(--toolId)
				++it;
			return it->getToolName();
		}
		return "[err: no tool fount at that id]";
	}
};

#endif /* TOOLS_H_ */
