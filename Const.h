//
// Created by Николай Карасов on 09/12/2018.
//

#ifndef MULTITHREADINGMONTECARLO_CONST_H
#define MULTITHREADINGMONTECARLO_CONST_H
const int N = 1000000; // число генераций

const int K = 4; // число потоков

const int len = N / K;

const double a = 0; // левая граница интегрирования

const double b = 5; // правая граница интегрирования
#endif //MULTITHREADINGMONTECARLO_CONST_H
