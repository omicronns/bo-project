#ifndef GUIDATA_H
#define GUIDATA_H

#include <vector>
#include "Tool.h"
#include "Toolchain.h"
#include "Workpoint.h"

class GUIData
{
    std::vector<Tool> toolchain;
    std::vector<Workpoint> workpoints;
    std::vector<int> solution;
    std::vector<double> temperature;

public:
    enum {
        toolchainEnum = 1,
        temperatureEnum,
        workointsEnum,
        solutionEnum
    };

    GUIData();
    void clear(int x = 0);

    void setToolchain(const std::vector<Tool> toolchain);
    const std::vector<Tool> & getToolchain() const;

    void setWorkpoints(const std::vector<Workpoint> workpoints);
    const std::vector<Workpoint> & getWorkpoint() const;

    void setSolution(const std::vector<int> solution);
    const std::vector<int> & getSolution() const;

    void temperature_pushBack(double x);
    const std::vector<double> & getTemperature() const;

private:
    void reset();
};

#endif // GUIDATA_H
