/*
 * ParseOptions.cpp
 *
 *  Created on: 12 Nov 2014
 *      Author: adasubu
 */

#include "ParseOptions.h"


bool ParseOptions::validNumericalValueExists(int index) {
    if(index >= m_Length)
        return false;
    else if(m_Opts[index][0] < '0' || m_Opts[index][0] > '9')
        return false;
    else
        return true;
}

int ParseOptions::findOption(std::string str) {
    for(int i = 0; i < m_Length; ++i)
        if(std::string(m_Opts[i]) == str)
            return i;
    return -1;
}

bool ParseOptions::getOptionValue(std::string spec, int &value) {
    int optSpecIndex = findOption(spec);
    if(optSpecIndex == -1)
        return false;
    else if(!validNumericalValueExists(optSpecIndex + 1))
        return false;
    else
        value = std::stoi(std::string(m_Opts[optSpecIndex + 1]));
    return true;
}

bool ParseOptions::getOptionValue(std::string spec, double &value) {
    int optSpecIndex = findOption(spec);
    if(optSpecIndex == -1)
        return false;
    else if(!validNumericalValueExists(optSpecIndex + 1))
        return false;
    else
        value = std::stod(std::string(m_Opts[optSpecIndex + 1]));
    return true;
}

bool ParseOptions::getOptionValue(std::string spec, std::string &value) {
    int optSpecIndex = findOption(spec);
    if(optSpecIndex == -1)
        return false;
    else if(optSpecIndex >= (m_Length - 1))
        return false;
    else
        value = std::string(m_Opts[optSpecIndex + 1]);
    return true;
}
