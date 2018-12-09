//
// Created by Николай Карасов on 09/12/2018.
//
#include "Multi.h"


void all(std::vector<double> &sample, std::vector<double> &mean, int thread_id, pcg64 &rng, std::vector<pcg64> &generators) {

    std::uniform_real_distribution<double> dist(a, b);

    for (int i = 0; i < len; i++) {
        mean[thread_id] += std::exp(dist(generators[K]));
    }

    mean[thread_id] *= (b - a) / N;
}