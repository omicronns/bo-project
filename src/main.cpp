/*
 * main.cpp
 *
 *  Created on: 5 Nov 2014
 *      Author: adasubu
 */

#include <iostream>
#include <fstream>
#include <string>

#include "ParseOptions.h"
#include "Problem.h"
#include "Solver.h"
#include "Toolchain.h"
#include "Random.h"

int main(int argc, const char **argv) {
	ParseOptions parser(argc, argv);

	if(parser.findOption("-g") != -1) {
	    std::string problemFilename;
        if(!parser.getOptionValue("-o", problemFilename)) {
            std::cerr << "problem output filename not specified\n";
            return 0;
        }
        std::fstream problemFile(problemFilename, std::ios::out);
        int workpointsCount;
        if(!parser.getOptionValue("-c", workpointsCount)) {
            std::cerr << "problem workpoints count not specified\n";
            return 0;
        }
        int maxtools;
        if(!parser.getOptionValue("-mt", maxtools)) {
            std::cerr << "max tools count per workpoint not specified\n";
            return 0;
        }
        std::string toolchainFilename;
        if(!parser.getOptionValue("-tc", toolchainFilename)) {
            std::cerr << "toolchain filename not specified\n";
            return 0;
        }
        int maxX = 1.0;
        parser.getOptionValue("-mx", maxX);
        int maxY = 1.0;
        parser.getOptionValue("-my", maxY);
        std::fstream toolchainFile(toolchainFilename, std::ios::in);
        Toolchain tlc;
        toolchainFile >> tlc;
        toolchainFile.close();
        problemFile << Problem(workpointsCount, maxtools, tlc, maxX, maxY);
        problemFile.close();
	}
	else if(parser.findOption("-s") != -1) {
        std::string problemFilename;
        if(!parser.getOptionValue("-i", problemFilename)) {
            std::cerr << "problem input filename not specified\n";
            return 0;
        }
        std::fstream problemFile(problemFilename, std::ios::in);
        std::string toolchainFilename;
        if(!parser.getOptionValue("-tc", toolchainFilename)) {
            std::cerr << "toolchain filename not specified\n";
            return 0;
        }
        std::fstream toolchainFile(toolchainFilename, std::ios::in);
        Toolchain tlc;
        toolchainFile >> tlc;
        toolchainFile.close();
        Problem pr(tlc);
        problemFile >> pr;
        problemFile.close();
        Solver slv(pr);
        std::cout << "cost: " << slv.calcCost() << "\n";
        double cost = slv.solve(100, 2, 1000);
        std::cout << slv << "cost: " << cost << "\n";
	}

	return 0;
}
