//
// Created by ghena on 03.12.2023.
//

#pragma once

#include <vector>

unsigned long long factorial(int num);

unsigned long long combinations(int n, int k);

unsigned long long arrangements(int n, int k);

unsigned long long permutations(int n);

unsigned long long combinationsWithRepetitions(int n, int k);

unsigned long long arrangementsWithRepetitions(int n, int k);

unsigned long long permutationsWithRepetitions(const std::vector<int> &counts);
