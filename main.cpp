#include <iostream>
#include <thread>
#include "Single.h"
#include "Multi.h"
#include <iomanip>

int main() {
    pcg64 rng(1);
    pcg64 rng_m(1);
    double m_mean = 0;

    std::vector<pcg64> generators;
    generators.reserve(K);

    for (size_t i = 0; i < K; ++i) {
//        generators.emplace_back(1);
//        generators[i].discard(static_cast<pcg_extras::pcg128_t>(len * 2));
        generators.push_back(rng_m);
        rng_m.discard(len * i);
    }

    std::vector<std::thread> t;
    t.reserve(K);

    std::vector<double> mean;
    mean.reserve(K);

    for (int i = 0; i < K; ++i) {
        t.emplace_back(std::thread(all, std::ref(mean), i, generators));
    }

    clock_t start = clock();
    for (auto &t_cur : t) {
        t_cur.join();
    }

    for (int i = 0; i < K; ++i) {
        m_mean += mean[i];
    }
    m_mean *= (b - a) / N;

    std::cout << "Calculation sample mean of sample of " << N << " random numbers in " << K << " threads took: "
              << float(clock() - start) << std::endl;

    start = clock();
    double s_mean = single_all(rng);
    std::cout << "Calculation sample mean of " << N << " random numbers in the single thread took: "
              << float(clock() - start) << std::endl << std::endl;

    std::cout << "Sample mean multi = " << std::scientific << m_mean << std::endl;
    std::cout << "Sample mean single = " << std::scientific << s_mean << std::endl;

    std::cout << "Difference = " << std::scientific << m_mean - s_mean << std::endl;
    return 0;
}