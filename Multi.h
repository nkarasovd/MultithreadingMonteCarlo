//
// Created by Николай Карасов on 09/12/2018.
//

#ifndef MULTITHREADINGMONTECARLO_TASKS_H
#define MULTITHREADINGMONTECARLO_TASKS_H

#include "Const.h"
#include <vector>
#include <random>
#include "pcg_random.hpp"

void all(std::vector<double> &sample, std::vector<double> &mean, int thread_id);

#endif //MULTITHREADINGMONTECARLO_TASKS_H
