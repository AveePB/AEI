#include <iostream>
#include <vector>
#include <unordered_map>

/**
 * @breif Finds the max sum of the range with reversed parity of the total sum.
 * @param v the vector of numbers.
 * @param totalSum the sum of all elements of v.
 * @param lPtr the left pointer of reversed range.
 * @param rPtr the righ pointer of reversed range.
 * @param sum the sum of reversed range.
*/
void findMaxRevParityRange(std::vector<int>& v, int totalSum, int& lPtr, int& rPtr, int& sum);


/**
 * @brief Creates all possible numbers from v (in given parity).
 * @param m the map of answers.
 * @param v the vector of numbers.
 * @param l the left pointer.
 * @param r the right pointer.
 * @param sum the current sum.
*/
void remember(std::unordered_map<int, std::pair<int, int>>& m, std::vector<int>& v, int l, int r, int sum);

// https://szkopul.edu.pl/problemset/problem/AWhdD7i4V7mupdKWVtpgfGSM/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Initialize variables and DS
    int k, nSegments, nQueries, totalSum = 0;
    char el;

    // Input
    std::cin >> nSegments >> nQueries;
    std::vector<int> vec(nSegments+1, 0);
    vec[0] = -1;

    for (int i = 1; i <= nSegments; i++) {
        std::cin >> el;
        // Strawberry (2)
        if (el == 'T') {
            totalSum += 2;
            vec[i] = 2;
        }

        // Vanilla (1)
        else {
            totalSum += 1;
            vec[i] = 1;
        }
    }

    // Find rev parity range
    int l = -1, r = -1, sum = -1;
    findMaxRevParityRange(vec, totalSum, l, r, sum);

    // Discover all possible numbers
    std::unordered_map<int, std::pair<int, int>> ans;
    
    remember(ans, vec, 1, nSegments, totalSum);
    if (l != -1 && r != -1 && sum > 0) remember(ans, vec, l, r, sum);

    // Handle all queries
    for (int i = 0; i < nQueries; i++) {
        std::cin >> k;
        
        // Segment wasn't found
        if (ans.find(k) == ans.end()) {
            std::cout << "NIE\n";
        }

        // Segment found
        else {
            std::cout << ans[k].first << ' ' << ans[k].second << '\n';
        }
    }
    
    return 0;
}

void findMaxRevParityRange(std::vector<int>& v, int totalSum, int& lPtr, int& rPtr, int& sum) {
    // Go from left
    int l = -1, Lsum = 0;
    for (int i = 1; i < v.size(); i++) {
        // Element is Odd
        if (v[i] == 1) {
            Lsum += totalSum - 1;
            l = i + 1;
            break;
        }
        else {
            Lsum -= v[i];
        }
    }

    // Go from right
    int r = -1, Rsum = 0;
    for (int i = v.size() - 1; i >= 1; i--) {
        // Element is Odd
        if (v[i] == 1) {
            Rsum += totalSum - 1;
            r = i - 1;
            break;
        }
        else {
            Rsum -= v[i];
        }
    }

    if (Rsum > Lsum) {
        lPtr = 1;
        rPtr = r;
        sum = Rsum;
    }
    else {
        lPtr = l;
        rPtr = v.size() - 1;
        sum = Lsum;
    }
}

void remember(std::unordered_map<int, std::pair<int, int>>& m, std::vector<int>& v, int l, int r, int sum) {
    // Go through vector
    while (l <= r) {
        // Save answer
        m[sum] = { l, r };

        // Left is even
        if (v[l] == 2) {
            l += 1;
        }

        // Right is even
        else if (v[r] == 2) {
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
