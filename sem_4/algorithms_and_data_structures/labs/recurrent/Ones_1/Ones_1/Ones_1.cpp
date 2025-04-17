#include <iostream>

long long factorial(int num) {
    if (num == 0)
        return 1; 
    long long result = 1;
    for (int i = 1; i <= num; i++) {
        result *= i;
    }

    return result;
}

long long mod = 1000000007;
long long binpow(long long a, long long p) {
    if (p == 0) {
        return 1;
    }
    else if (p % 2 == 1) {
        return (binpow(a, p - 1) * a) % mod;
    }
    else {
        long long b = binpow(a, p / 2) % mod;
        return (b * b) % mod;
    }
}

long long inv(long long a) {
    return binpow(a, mod - 2) % mod;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, k;
    std::cin >> n >> k;

    //long long denominator = (factorial(k) * factorial(n - k));
    //long long result = (factorial(n) / denominator);
   
    long long numenator = 1;
    for (long long i = n; i > n - k; i--) {
        numenator *= i;
        numenator %= mod;
    }

    long long denominator = 1;
    for (long long i = 1; i <= k; i++) {
        denominator *= i;
        denominator %= mod;
    }

    long long result = (numenator * inv(denominator)) % mod;
    std::cout << result;
    return 0;
}
