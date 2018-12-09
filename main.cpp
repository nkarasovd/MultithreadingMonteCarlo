#include <iostream>
#include <thread>
#include "Single.h"
#include "Multi.h"

int main() {
    pcg64 rng(1);
    std::vector<double> m_res(N);
    std::vector<std::thread> t1, t2, t3;

    clock_t start;


    std::vector<double> s_res(N);

    /**
     * Подсчет интеграла
     */

    double m_mean = 0;
    std::vector<double> m_mean_sample(K);

    start = clock();
    for (int i = 0; i < K; ++i) {
        t3.emplace_back(std::thread(all, std::ref(m_res), std::ref(m_mean_sample), i));
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
    std::cout << "Sample mean multi = " << m_mean << std::endl;
    std::cout << "Sample mean single = " << s_mean << std::endl;
    return 0;
}