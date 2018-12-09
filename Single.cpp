//
// Created by Николай Карасов on 09/12/2018.
//
#include <random>
#include "Single.h"

void single_generate(std::vector<double> &sample, pcg64 &rng) {
    std::uniform_real_distribution<double> dist(a, b);
    for (int i = 0; i < N; ++i) {
        sample[i] = dist(rng);
    }
}

void single_calculate(std::vector<double> &sample) {
    for (int i = 0; i < N; ++i) {
        sample[i] = std::exp(sample[i]);
    }
}

double single_mean(std::vector<double> &sample) {
    double result = 0;
    for (int i = 0; i < N; ++i) {
        result += (b - a) / N * sample[i];
    }

    return result;
}

double single_all(std::vector<double> &sample, pcg64 &rng) {
    std::uniform_real_distribution<double> dist(a, b);
    double result = 0;
    for (int i = 0; i < N; ++i) {
        result += std::exp(dist(rng));
    }
    result *= (b - a) / N;
    return result;
}