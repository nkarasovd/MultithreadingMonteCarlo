//
// Created by Николай Карасов on 09/12/2018.
//

#ifndef MULTITHREADINGMONTECARLO_SINGLE_H
#define MULTITHREADINGMONTECARLO_SINGLE_H

#include "Const.h"
#include <vector>
#include "pcg_random.hpp"

void single_generate(std::vector<double> &sample, pcg64 &rng);

void single_calculate(std::vector<double> &sample);

double single_mean(std::vector<double> &sample);

double single_all(std::vector<double> &sample, pcg64 &rng);

#endif //MULTITHREADINGMONTECARLO_SINGLE_H
