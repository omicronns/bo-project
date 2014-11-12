/*
 * ParseOptions.h
 *
 *  Created on: 12 Nov 2014
 *      Author: adasubu
 */

#ifndef PARSEOPTIONS_H_
#define PARSEOPTIONS_H_

#include <string>

class ParseOptions {
private:
    const int m_Length;
    const char **m_Opts;
    /*
     * \brief   Checks if numerical value exists at given index
     */
    bool validNumericalValueExists(int index);

public:
    ParseOptions(int argc, const char **argv)
            : m_Length(argc), m_Opts(argv) {
    }

    /*
     * \brief   Finds option specifier position, returns -1 if not found
     */
    int findOption(std::string str);

    /*
     * \brief   Gets option value of specified type if specified,
     *          returns true if valid value found,
     *          returns false if not
     */
    bool getOptionValue(std::string spec, int &value);
    bool getOptionValue(std::string spec, double &value);
    bool getOptionValue(std::string spec, std::string &value);
};

#endif /* PARSEOPTIONS_H_ */
