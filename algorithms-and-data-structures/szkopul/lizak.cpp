#include <iostream>
#include <vector>

const int MAX_VAL = 2e6 + 7;
const int MAX_SIZE = 1e6 + 7;

/**
 * @breif Finds the max sum of the range with reversed parity of the total sum.
 * @param arr the array of numbers.
 * @param size the size of an array.
 * @param totalSum the sum of all elements of v.
 * @param lPtr the left pointer of reversed range.
 * @param rPtr the righ pointer of reversed range.
 * @param sum the sum of reversed range.
*/
void findMaxRevParityRange(int* arr, int size, int totalSum, int& lPtr, int& rPtr, int& sum);

/**
 * @brief Creates all possible numbers from v (in given parity).
 * @param m the map of answers.
 * @param arr the array of numbers.
 * @param l the left pointer.
 * @param r the right pointer.
 * @param sum the current sum.
*/
void remember(std::pair<int, int>* ans, int* arr, int l, int r, int sum);

// https://szkopul.edu.pl/problemset/problem/AWhdD7i4V7mupdKWVtpgfGSM/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Initialize variables
    int k, nSegments, nQueries, totalSum = 0, arr[MAX_SIZE];
    char el;

    // Initialize data structure
    std::pair<int, int> ans[MAX_VAL];
    for (int i = 0; i < MAX_VAL; i++) ans[i] = { -1, -1 };

    // Input
    std::cin >> nSegments >> nQueries;
    arr[0] = -1;

    for (int i = 1; i <= nSegments; i++) {
        std::cin >> el;
        // Strawberry (2)
        if (el == 'T') {
            totalSum += 2;
            arr[i] = 2;
        }

        // Vanilla (1)
        else {
            totalSum += 1;
            arr[i] = 1;
        }
    }

    // Find rev parity range
    int l = -1, r = -1, sum = -1;
    findMaxRevParityRange(arr, nSegments+1, totalSum, l, r, sum);

    // Discover all possible numbers
    remember(ans, arr, 1, nSegments, totalSum);
    if (l != -1 && r != -1 && sum > 0) remember(ans, arr, l, r, sum);

    // Handle all queries
    for (int i = 0; i < nQueries; i++) {
        std::cin >> k;
        
        // Segment wasn't found
        if (ans[k].first == -1 || ans[k].second == -1) {
            std::cout << "NIE\n";
        }

        // Segment found
        else {
            std::cout << ans[k].first << ' ' << ans[k].second << '\n';
        }
    }
    
    return 0;
}

void findMaxRevParityRange(int* arr, int size, int totalSum, int& lPtr, int& rPtr, int& sum) {
    // Go from left
    int l = -1, Lsum = 0;
    for (int i = 1; i < size; i++) {
        // Element is Odd
        if (arr[i] == 1) {
            Lsum += totalSum - 1;
            l = i + 1;
            break;
        }
        else {
            Lsum -= arr[i];
        }
    }

    // Go from right
    int r = -1, Rsum = 0;
    for (int i = size - 1; i >= 1; i--) {
        // Element is Odd
        if (arr[i] == 1) {
            Rsum += totalSum - 1;
            r = i - 1;
            break;
        }
        else {
            Rsum -= arr[i];
        }
    }

    if (Rsum > Lsum) {
        lPtr = 1;
        rPtr = r;
        sum = Rsum;
    }
    else {
        lPtr = l;
        rPtr = size - 1;
        sum = Lsum;
    }
}

void remember(std::pair<int, int>* ans, int* arr, int l, int r, int sum) {
    // Go through array
    while (l <= r) {
        // Save answer
        ans[sum] = { l, r };

        // Left is even
        if (arr[l] == 2) {
            l += 1;
        }

        // Right is even
        else if (arr[r] == 2) {
            r -= 1;
        }

        // Left & Right are odd
        else {
            l += 1;
            r -= 1;
        }

        // Decrement sum
        sum -= 2;
    }
}
