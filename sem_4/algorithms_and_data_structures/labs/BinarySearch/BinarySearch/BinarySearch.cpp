#include <iostream>
#include <vector>

bool b(std::vector<long long> v, long long n, long long a) {
    long long L = 0, R = n, C;

    while (L < R) {
        C = (L + R) >> 1;
        if (a == v[C]) {
            return true;
        }
        else if (a < v[C]) {
            R = C;
        }
        else {
            L = C + 1;
        }
    }

    return false;
}

long long l(std::vector<long long> v, long long n, long long a) {
    long long L = 0, R = n, C;

    while (L < R) {
        C = (L + R)>>1;
        if (a <= v[C]) {
            R = C;
        }
        else {
            L = C + 1;
        }
    }
    return L;
}

long long u(std::vector<long long> v, long long n, long long a) {
    long long L = 0, R = n, C;

    while (L < R) {
        C = (L + R)>>1;
        
        if (a < v[C]) {
            R = C;
        }
        else {
            L = C + 1;
        }
    }
    return L;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n;
    std::cin >> n;
    std::vector<long long> a(n);

    for (long long i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    long long number;
    long long countRequests;

    std::cin >> countRequests;
    for (long long i = 0; i < countRequests; i++) {
        std::cin >> number;
        std::cout << b(a, n, number) << " " << l(a, n, number) << " " << u(a, n, number) << std::endl;
    }

    return 0;
}
