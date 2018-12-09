#include <iostream>
#include <thread>
#include "Single.h"
#include "Multi.h"
#include "pcg_random.hpp"

int main() {
    pcg64 rng(1);
    std::vector<double> m_res(N);
    std::vector<std::thread> t1, t2, t3;

    /**
     * Генерация
     */
    clock_t start = clock();
    for (int i = 0; i < K; ++i) {
        t1.emplace_back(std::thread(generate, std::ref(m_res), i));
    }

    for (auto &t : t1) {
        t.join();
    }

    std::cout << "Generation of sample of " << N << " random numbers in " << K << " threads took: "
              << float(clock() - start) << std::endl;


    std::vector<double> s_res(N);
    start = clock();
    single_generate(s_res, rng);

    std::cout << "Generation of sample of " << N << " random numbers in single thread took: "
              << float(clock() - start) << std::endl << std::endl;

    /**
     * Вычисление экспоненты
     */

    start = clock();
    for (int i = 0; i < K; ++i) {
        t2.emplace_back(std::thread(calculate, std::ref(m_res), i));
    }

    for (auto &t : t2) {
        t.join();
    }

    std::cout << "Calculation exp of sample of " << N << " random numbers in " << K << " threads took: "
              << float(clock() - start) << std::endl;

    start = clock();
    single_calculate(s_res);
    std::cout << "Calculation exp of sample of " << N << " random numbers in single thread took: "
              << float(clock() - start) << std::endl << std::endl;


    /**
     * Подсчет интеграла
     */

    double m_mean = 0;
    std::vector<double> m_mean_sample(K);

    start = clock();
    for (int i = 0; i < K; ++i) {
        t3.emplace_back(std::thread(sample_mean, std::ref(m_res), std::ref(m_mean_sample), i));
    }

    for (auto &t : t3) {
        t.join();
    }

    for (int i = 0; i < K; i++) {
        m_mean += m_mean_sample[i];
    }

    std::cout << "Calculation sample mean of sample of " << N << " random numbers in " << K << " threads took: "
              << float(clock() - start) << std::endl;

    start = clock();
    double s_mean = single_mean(s_res);
    std::cout << "Calculation sample mean of " << N << " random numbers in the single thread took: "
              << float(clock() - start) << std::endl << std::endl;
    std::cout << "Sample mean multi = " << m_mean << std::endl;
    std::cout << "Sample mean single = " << s_mean << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}