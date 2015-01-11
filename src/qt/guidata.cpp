#include "guidata.h"
#include <vector>
#include "Tool.h"
#include "Toolchain.h"
#include "Workpoint.h"
#include <iostream>

GUIData::GUIData()
{
}

void GUIData::reset() {
    this->temperature.clear();
    this->solution.clear();
    this->toolchain.clear();
    this->workpoints.clear();
}

void GUIData::clear(int x) {
    switch (x) {
    case 0:
        reset();
        std::cout << "all cleared\n";
        break;
    case GUIData::toolchainEnum:
        toolchain.clear();
        std::cout << "toolchain cleared\n";
        break;
    case GUIData::temperatureEnum:
        temperature.clear();
        std::cout << "temperature cleared\n";
        break;
    case GUIData::workointsEnum:
        workpoints.clear();
        std::cout << "workpoints cleared\n";
        break;
    case GUIData::solutionEnum:
        solution.clear();
        std::cout << "solution cleared\n";
        break;
    }
}

void GUIData::setToolchain(const std::vector<Tool> toolchain) {
    this->toolchain = toolchain;
}

const std::vector<Tool> & GUIData::getToolchain() const {
    return toolchain;
}

void GUIData::setWorkpoints(const std::vector<Workpoint> workpoints) {
    this->workpoints = workpoints;
}

const std::vector<Workpoint> & GUIData::getWorkpoint() const {
    return workpoints;
}

void GUIData::setSolution(const std::vector<int> solution) {
    this->solution = solution;
}

const std::vector<int> & GUIData::getSolution() const {
    return solution;
}

void GUIData::temperature_pushBack(double x) {
    this->temperature.push_back(x);
}

const std::vector<double> & GUIData::getTemperature() const {
    return temperature;
}
