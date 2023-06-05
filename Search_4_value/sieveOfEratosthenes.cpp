#include "all_functions.h"

int_vector sieveOfEratosthenes(int n) {
    std::vector<bool> A(n+1, true); // initialize all values to true
    std::vector<int> primes;

    for (int i = 2; i <= sqrt(n); i++) {
        if (A[i]) {
            for (int j = i*i; j <= n; j += i) {
                A[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (A[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}