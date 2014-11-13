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
#include "Solver.h"

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
        double temp0 = 1000;
        parser.getOptionValue("-t0", temp0);
        double tempf = 1;
        parser.getOptionValue("-tf", tempf);
        double alpha = 1;
        parser.getOptionValue("-al", alpha);
        double beta = 0.1;
        parser.getOptionValue("-bt", beta);
        double gamma = 0.1;
        parser.getOptionValue("-gm", gamma);
        int iters = 100;
        parser.getOptionValue("-it", iters);
        Solver slv(pr);
        std::cout << "cost: " << slv.calcCost() << "\n";
        std::list<double> costs;
        double cost = slv.solve(temp0, tempf, alpha, beta, gamma, iters, costs);
        std::cout << slv << "cost: " << cost << "\n";
	}

	return 0;
}
