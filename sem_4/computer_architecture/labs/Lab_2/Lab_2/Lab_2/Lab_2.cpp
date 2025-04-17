#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <omp.h>
#include <chrono>

double f(double x) {
    if (x >= 0 && x <= M_PI / 2) {
        return cos(x);
    }
    else if (x > M_PI / 2 && x <= 2) {
        return M_PI / 2 - x;
    }
    return 0;
}

double calc_h(double a, double b, int N) {
    return ((b - a) / N);
}

double Xk(double a, double h, int k) {
    return (a + h * k);
}

double calc_f_(double x) {
    if (x >= 0 && x <= M_PI / 2) {
        return (-1) * sin(x);
    }
    else if (x > M_PI / 2 && x <= 2) {
        return -1.0;
    }
    return 0.0;
}

int main(int argc, char* argv[]) {
    int N = atoi(argv[argc-1]);
    double a = 0.0;
    double b = 2.0;

    double h = calc_h(a, b, N);
    double max_f_ = -INFINITY;
    double max_f2_ = -INFINITY;
    double f_ = 0;
    double f2_;
    double epsilon = 1e-6;
    double expected_f;
    double max_expected_f = calc_f_(a);
    auto start_time = omp_get_wtime();
    omp_set_num_threads(4);

#pragma omp parallel sections num_threads(2)
    {
#pragma omp section
        {
#pragma omp parallel for
            for (int i = 0; i <= N; i++) {
                if (i == N) {
                    f_ = (f(Xk(a, h, i)) - f(Xk(a, h, i - 1))) / h;
                    if (max_f_ < f_) {
                        max_f_ = f_;
                    }
                }
                else {
                    f_ = (f(Xk(a, h, i + 1)) - f(Xk(a, h, i))) / h;
                    if (max_f_ < f_) {
                        max_f_ = f_;
                    }
                }

                expected_f = calc_f_(Xk(a, h,i));
                if (max_expected_f < expected_f) {
                    max_expected_f = expected_f;
                }
            }
        }

#pragma omp section
        {
            int N2 = 4 * N;
            double h2 = calc_h(a, b, N2);
            f2_ = 0;

#pragma omp parallel for reduction(max:max_f2_)
            for (int i = 0; i <= N2; i++) {
                if (i == N2) {
                    f2_ = (f(Xk(a, h2, i)) - f(Xk(a, h2, i - 1))) / h2;
                    if (max_f2_ < f_) {
                        max_f2_ = f_;
                    }
                }
                else {
                    f2_ = (f(Xk(a, h2, i + 1)) - f(Xk(a, h2, i))) / h2;
                    if (max_f2_ < f2_) {
                        max_f2_ = f2_;
                    }
                }
                //std::cout << "Thread " << omp_get_thread_num() << ", f2' = " << f2_ << std::endl;
            }
        }
    }
    std::cout << "Max value |f'(x)| on [" << a << ", " << b << "]" << " for N = " << N << " is " << max_f_ << " f2 = " << max_f2_ << std::endl;

    auto time_end = omp_get_wtime();
    std::cout << "Expected value : " << max_expected_f << std::endl;
    std::cout << "Time: " << time_end - start_time << " sec" << std::endl;
    return 0;
}