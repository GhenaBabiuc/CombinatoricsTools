#include <iostream>
#include <vector>
#include <conio.h>
#include "CombinatoricsFunctions.h"

using namespace std;

void pause() {
    cout << "Press Enter to continue...";
    _getch();
    cout << endl;
}

int main() {
    int choice;
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
                cout << "Factorial: " << factorial(num) << endl;
                pause();
                break;
            }
            case 2: {
                int n, k;
                cout << "Enter n for combinations: ";
                cin >> n;
                cout << "Enter k for combinations: ";
                cin >> k;
                cout << "Combinations: " << combinations(n, k) << endl;
                pause();
                break;
            }
            case 3: {
                int n, k;
                cout << "Enter n and k for arrangements: ";
                cin >> n >> k;
                cout << "Arrangements: " << arrangements(n, k) << endl;
                pause();
                break;
            }
            case 4: {
                int n;
                cout << "Enter n for permutations: ";
                cin >> n;
                cout << "Permutations: " << permutations(n) << endl;
                pause();
                break;
            }
            case 5: {
                int n, k;
                cout << "Enter n and k for combinations with repetitions: ";
                cin >> n >> k;
                cout << "Combinations with Repetitions: " << combinationsWithRepetitions(n, k) << endl;
                pause();
                break;
            }
            case 6: {
                int n, k;
                cout << "Enter n and k for arrangements with repetitions: ";
                cin >> n >> k;
                cout << "Arrangements with Repetitions: " << arrangementsWithRepetitions(n, k) << endl;
                pause();
                break;
            }
            case 7: {
                int count;
                cout << "Enter the count of numbers for permutations with repetitions: ";
                cin >> count;
                vector<int> counts(count);
                cout << "Enter the numbers: ";
                for (int i = 0; i < count; ++i) {
                    cin >> counts[i];
                }
                cout << "Permutations with Repetitions: " << permutationsWithRepetitions(counts) << endl;
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