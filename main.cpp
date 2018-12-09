#include <iostream>
#include <thread>
#include "Single.h"
#include "Multi.h"
#include <iomanip>

int main() {
    pcg64 rng(1);

    std::vector<double> m_res(N);
    std::vector<double> s_res(N);

    std::vector<std::thread> t1, t2, t3;


    double m_mean = 0;
    std::vector<double> m_mean_sample(K);

    std::vector<pcg64> generators(K);

    for (size_t i = 0; i < K; ++i) {
        generators.emplace_back(1);
        generators[i].discard(static_cast<pcg_extras::pcg128_t>(2 * len * i));
    }

    clock_t start = clock();
    for (int i = 0; i < K; ++i) {
        t3.emplace_back(std::thread(all, std::ref(m_res), std::ref(m_mean_sample), i, std::ref(rng), std::ref(generators)));
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
    double s_mean = single_all(s_res, rng);
    std::cout << "Calculation sample mean of " << N << " random numbers in the single thread took: "
              << float(clock() - start) << std::endl << std::endl;
    
    std::cout << "Sample mean multi = " << std::scientific <<  m_mean << std::endl;
    std::cout << "Sample mean single = " << std::scientific << s_mean << std::endl;

    std::cout << "Разность = " << std::scientific << m_mean - s_mean << std::endl;
    return 0;
}