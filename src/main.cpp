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

	Solver slv(Problem(2, 5, tlc));

    std::cout << tlc << slv.getProblem();

	std::vector<int> solution = slv.getSolution();

    for(std::vector<int>::iterator it = solution.begin(); it != solution.end(); ++it) {
        std::cout << *it << "; ";
    }
    std::cout << "\n";
    std::cout << "\n" << slv.calcCost();

//    for(int i = 0; i < 1000; ++i)
//        slv.permuteSolution(100);
//    solution = slv.getSolution();
//    std::cout << "\n";
//
//    for(std::vector<int>::iterator it = solution.begin(); it != solution.end(); ++it) {
//        std::cout << *it << "; ";
//    }
//
//	std::cout << "\n" << slv.calcCost();

	return 0;
}
