/*
 * Random.h
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#ifndef RANDOM_H_
#define RANDOM_H_

#include <random>
#include <chrono>

class Random {
    std::default_random_engine rand;

public:
    Random(int seed = std::chrono::system_clock::now().time_since_epoch().count());
    int randi();
    int randi(int min, int max);
    double randf();
    double randf(double min, double max);
};

#endif /* RANDOM_H_ */
