/*
 * main.cpp
 *
 *  Created on: 5 Nov 2014
 *      Author: adasubu
 */

#include <iostream>
#include <string>
#include <unordered_set>

#include "Problem.h"

int main(void) {
	std::cout << "hello" << "\n";

	Workpoint pt(0, 0, 1);

	pt.pushTool(5);
	pt.pushTool(3);
	pt.pushTool(2);
	std::cout << pt.popTool() << " " << pt.toolsCount() << "\n";
	std::cout << pt.popTool() << " " << pt.toolsCount() << "\n";
	std::cout << pt.popTool() << " " << pt.toolsCount() << "\n";
	std::cout << pt.popTool() << " " << pt.toolsCount() << "\n";

	return 0;
}
