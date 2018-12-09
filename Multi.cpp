//
// Created by Николай Карасов on 09/12/2018.
//
#include "Multi.h"


void all(std::vector<double> &sample, std::vector<double> &mean, int thread_id) {
    pcg64 rng(1);
    std::uniform_real_distribution<double> dist(a, b);
    rng.discard(static_cast<pcg_extras::pcg128_t>(len * thread_id));

    for (int i = len * thread_id; i < len * (thread_id + 1); i++) {
        mean[thread_id] += std::exp(dist(rng));
    }

    mean[thread_id] *= (b - a) / N;
}