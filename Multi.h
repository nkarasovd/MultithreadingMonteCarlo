//
// Created by Николай Карасов on 09/12/2018.
//

#ifndef MULTITHREADINGMONTECARLO_TASKS_H
#define MULTITHREADINGMONTECARLO_TASKS_H

#include "Const.h"
#include <vector>
#include <random>
#include "pcg_random.hpp"


void generate(std::vector<double> &sample, int thread_id);

void calculate(std::vector<double> &sample, int thread_id);

void sample_mean(std::vector<double> &sample, std::vector<double> &mean, int thread_id);


#endif //MULTITHREADINGMONTECARLO_TASKS_H
