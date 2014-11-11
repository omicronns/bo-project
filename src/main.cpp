/*
 * main.cpp
 *
 *  Created on: 5 Nov 2014
 *      Author: adasubu
 */

#include <iostream>
#include <string>

#include "Problem.h"
#include "Solver.h"
#include "Toolchain.h"
#include "Random.h"

int main(void) {
	std::cout << "hello" << "\n";

	Toolchain tlc;
    tlc.addTool("wiertło");
    tlc.addTool("nóz");
    tlc.addTool("łyżka");
    tlc.addTool("widelec");

	Solver slv(Problem(10, 5, tlc));

    std::cout << tlc << slv.getProblem();

	std::vector<int> solution = slv.getSolution();

	for(std::vector<int>::iterator it = solution.begin(); it != solution.end(); ++it) {
	    std::cout << *it << "; ";
	}

	return 0;
}
