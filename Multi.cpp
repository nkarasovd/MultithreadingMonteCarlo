//
// Created by Николай Карасов on 09/12/2018.
//
#include "Multi.h"


void all(std::vector<double> &mean, int thread_id, std::vector<pcg64> generators) {

    std::uniform_real_distribution<double> dist(a, b);
    pcg64 rng = generators[thread_id];
    double _mean = 0;

    for (int i = 0; i < len; ++i) {
        _mean += std::exp(dist(rng));
    }


    mean[thread_id] = _mean;
}