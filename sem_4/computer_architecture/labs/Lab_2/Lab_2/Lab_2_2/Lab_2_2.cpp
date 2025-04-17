#include <iostream>
#include <omp.h>
#include <chrono>


double f(double x) {
    return x * x - 2 * x;
}

double Xk(double a, double h, int k) {
    return (a + h * k);
}

double calc_h(double a, double b, int N) {
    return ((b - a) / N);
}

double expected_integral(double a, double b) {
    return b * b * b / 3 - b * b - a * a * a / 3 + a * a;
}
int main(int argc, char* argv[]) {

    int N = atoi(argv[1]);
    double a = 0.0;
    double b = 1.0;

    double h = calc_h(a, b, N);
    double integral = 0.0;
    auto start_time = omp_get_wtime();
    omp_set_num_threads(4);
#pragma omp parallel num_threads(4) for reduction(+:integral)
    for (int i = 0; i <= N; ++i) {
        integral += f(Xk(a, h, i)) * h;
    }
    std::cout << "Integral f(x)| on [" << a << ", " << b << "] = " << integral << std::endl;

    std::cout << "Expected value: " << expected_integral(a, b) << std::endl;
    auto end_time = omp_get_wtime();
    std::cout << "Time: " << end_time - start_time << " sec" << std::endl;
    return 0;
}
