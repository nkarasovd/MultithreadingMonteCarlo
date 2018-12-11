//
// Created by Николай Карасов on 09/12/2018.
//
#include <random>
#include "Single.h"

double single_all(pcg64 rng) {

    std::uniform_real_distribution<double> dist(a, b);
    double result = 0;

    for (int i = 0; i < N; ++i) {
        result += std::exp(dist(rng));
    }

    result *= (b - a) / N;
    return result;
}