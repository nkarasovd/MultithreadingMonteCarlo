//
// Created by Николай Карасов on 09/12/2018.
//
#include "Multi.h"


void all(std::vector<double> &sample, std::vector<double> &mean, int thread_id, pcg64 &rng,
         std::vector<pcg64> &generators) {


    std::uniform_real_distribution<double> dist(a, b);
    double _mean = 0;
    for (int i = 0; i < len; ++i) {
        _mean += std::exp(dist(generators[thread_id]));
    }

    mean[thread_id] = _mean;
}