//
// Created by Николай Карасов on 09/12/2018.
//

#ifndef MULTITHREADINGMONTECARLO_SINGLE_H
#define MULTITHREADINGMONTECARLO_SINGLE_H

#include "Const.h"
#include <vector>
#include "pcg_random.hpp"

double single_all(std::vector<double> &sample, pcg64 &rng);

#endif //MULTITHREADINGMONTECARLO_SINGLE_H
