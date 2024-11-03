#include <iostream>

const int NINF = -1e5-7;

// https://szkopul.edu.pl/problemset/problem/qLeI5R3zf28Y6FHVcfJPuj0T/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    int n, num, currSum=NINF, bestSum=NINF;

    // Analyze numbers
    while (true) {
        // Load next number
        std::cin >> num;
        if (num == 0) break;

        // Update sums
        currSum = std::max(currSum+num, num);
        bestSum = std::max(bestSum, currSum);
    }

    std::cout << bestSum;
    return 0;
}