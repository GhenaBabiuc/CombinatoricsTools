//
// Created by ghena on 03.12.2023.
//

#include "CombinatoricsFunctions.h"

unsigned long long factorial(int num) {
    if (num <= 1) {
        return 1;
    }
    return num * factorial(num - 1);
}

unsigned long long combinations(int n, int k) {
    // using the formula C(n, k) = n! / (k! * (n-k)!)
    if (k < 0 || k > n) {
        return 0;
    }

    unsigned long long result = 1;
    for (int i = 1; i <= k; i++) {
        result *= n--;
        result /= i;
    }

    return result;
}

unsigned long long arrangements(int n, int k) {
    // using the formula A(n, k) = n! / (n-k)!
    if (k < 0 || k > n) {
        return 0;
    }

    unsigned long long result = 1;
    for (int i = n; i > n - k; i--) {
        result *= i;
    }

    return result;
}

unsigned long long permutations(int n) {
    // using the formula P(n) = n!
    return factorial(n);
}

unsigned long long combinationsWithRepetitions(int n, int k) {
    // using the formula C(n, k) = (n + k - 1)! / (k! * (n-1)!)
    unsigned long long result = 1;
    for (int i = 1; i <= k; i++) {
        result *= (n + i - 1);
        result /= i;
    }
    return result;
}

unsigned long long arrangementsWithRepetitions(int n, int k) {
    // using the formula A(n, k) = n^k
    unsigned long long result = 1;
    for (int i = 0; i < k; i++) {
        result *= n;
    }
    return result;
}

unsigned long long permutationsWithRepetitions(const std::vector<int> &counts) {
    // using the formula P(n1, n2, ..., nk) = (n1 + n2 + ... + nk)! / (n1! * n2! * ... * nk!)
    int total = 0;
    unsigned long long numerator = 1;
    unsigned long long denominator = 1;

    for (int count: counts) {
        total += count;
    }

    numerator = factorial(total);

    for (int count: counts) {
        denominator *= factorial(count);
    }

    return numerator / denominator;
}