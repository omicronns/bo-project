/*
 * Random.cpp
 *
 *  Created on: 11 Nov 2014
 *      Author: adasubu
 */

#include "Random.h"
#include <cstdlib>

Random::Random(int seed)
        : rand(seed) {
}

int Random::randi() {
    std::uniform_int_distribution<int> dist;
    return dist(rand);
}

int Random::randi(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rand);
}

double Random::randf() {
    std::uniform_real_distribution<double> dist;
    return dist(rand);
}

double Random::randf(double min, double max) {
    std::uniform_real_distribution<double> dist(min, max);
    return dist(rand);
}
