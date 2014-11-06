/*
 * main.cpp
 *
 *  Created on: 5 Nov 2014
 *      Author: adasubu
 */

#include <iostream>
#include <string>
#include <unordered_set>

#include "Tools.h"

int main(void) {
	std::cout << "hello" << "\n";

	ToolChain tlc;

	tlc.addTool("wiertlo");
	tlc.addTool("mlotek");

	std::cout << tlc.getToolName(2) << "\n";
}
