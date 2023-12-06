#include <iostream>
#include <vector>
#include <conio.h>
#include "BigInt.hpp"

using namespace std;

BigInt factorial(const BigInt &n);

BigInt combinations(const BigInt &n, const BigInt &k);

BigInt arrangements(const BigInt &n, const BigInt &k);

BigInt permutations(const BigInt &n);

BigInt combinationsWithRepetitions(const BigInt &n, const BigInt &k);

BigInt arrangementsWithRepetitions(const BigInt &n, const BigInt &k);

BigInt permutationsWithRepetitions(const std::vector<int> &counts);

void pause();

int main() {
    int choice;
    int n, k;
    do {
        cout << "Menu:\n";
        cout << "1. Factorial\n";
        cout << "2. Combinations\n";
        cout << "3. Arrangements\n";
        cout << "4. Permutations\n";
        cout << "5. Combinations with Repetitions\n";
        cout << "6. Arrangements with Repetitions\n";
        cout << "7. Permutations with Repetitions\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int num;
                cout << "Enter a number: ";
                cin >> num;
                BigInt result = factorial(BigInt(num));
                cout << "Factorial: " << result << endl;
                pause();
                break;
            }
            case 2: {
                cout << "Enter n for combinations: ";
                cin >> n;
                cout << "Enter k for combinations: ";
                cin >> k;
                BigInt result = combinations(BigInt(n), BigInt(k));
                cout << "Combinations: " << result << endl;
                pause();
                break;
            }
            case 3: {
                cout << "Enter n for arrangements: ";
                cin >> n;
                cout << "Enter k for arrangements: ";
                cin >> k;
                BigInt result = arrangements(BigInt(n), BigInt(k));
                cout << "Arrangements: " << result << endl;
                pause();
                break;
            }
            case 4: {
                cout << "Enter n for permutations: ";
                cin >> n;
                BigInt result = permutations(BigInt(n));
                cout << "Permutations: " << result << endl;
                pause();
                break;
            }
            case 5: {
                cout << "Enter n for combinations with repetitions: ";
                cin >> n;
                cout << "Enter k for combinations with repetitions: ";
                cin >> k;
                BigInt result = combinationsWithRepetitions(BigInt(n), BigInt(k));
                cout << "Combinations with Repetitions: " << result << endl;
                pause();
                break;
            }
            case 6: {
                cout << "Enter n for arrangements with repetitions: ";
                cin >> n;
                cout << "Enter k for arrangements with repetitions: ";
                cin >> k;
                BigInt result = arrangementsWithRepetitions(BigInt(n), BigInt(k));
                cout << "Arrangements with Repetitions: " << result << endl;
                pause();
                break;
            }
            case 7: {
                int count;
                cout << "Enter the count of numbers for permutations with repetitions: ";
                cin >> count;
                vector<int> counts(count);
                for (int i = 0; i < count; i++) {
                    cout << "Enter the number nr " << i << ": ";
                    cin >> counts[i];
                }
                BigInt result = permutationsWithRepetitions(counts);
                cout << "Permutations with Repetitions: " << result << endl;
                pause();
                break;
            }
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0);

    return 0;
}

void pause() {
    cout << "Press Enter to continue...\n";
    _getch();
    cout << endl;
}

BigInt factorial(const BigInt &n) {
    if (n <= 1) {
        return 1;
    }
    BigInt result = 1;
    for (BigInt i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

BigInt combinations(const BigInt &n, const BigInt &k) {
    // using the formula C(n, k) = n! / (k! * (n-k)!)
    if (k < 0 || k > n) {
        return 0;
    }

    BigInt result = 1;
    for (BigInt i = 1; i <= k; ++i) {
        result *= n - i + 1;
        result /= i;
    }

    return result;
}

BigInt arrangements(const BigInt &n, const BigInt &k) {
    // using the formula A(n, k) = n! / (n-k)!
    if (k < 0 || k > n) {
        return 0;
    }

    BigInt result = 1;
    for (BigInt i = n - k + 1; i <= n; ++i) {
        result *= i;
    }

    return result;
}

BigInt permutations(const BigInt &n) {
    // using the formula P(n) = n!
    return factorial(n);
}

BigInt combinationsWithRepetitions(const BigInt &n, const BigInt &k) {
    // using the formula C(n, k) = (n + k - 1)! / (k! * (n-1)!)
    BigInt result = 1;
    for (BigInt i = 1; i <= k; ++i) {
        result *= (n + i - 1);
        result /= i;
    }
    return result;
}

BigInt arrangementsWithRepetitions(const BigInt &n, const BigInt &k) {
    // using the formula A(n, k) = n^k
    BigInt result = 1;
    for (BigInt i = 0; i < k; ++i) {
        result *= n;
    }
    return result;
}

BigInt permutationsWithRepetitions(const std::vector<int> &counts) {
    // using the formula P(n1, n2, ..., nk) = (n1 + n2 + ... + nk)! / (n1! * n2! * ... * nk!)
    int total = 0;
    BigInt numerator = 1;
    BigInt denominator = 1;

    for (int count: counts) {
        total += count;
    }

    numerator = factorial(total);

    for (int count: counts) {
        denominator *= factorial(count);
    }

    return numerator / denominator;
}