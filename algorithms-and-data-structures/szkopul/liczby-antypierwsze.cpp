#include <iostream>
#include <algorithm>
#include <vector>

typedef std::vector<std::pair<int, int>> highlyComposites;

// Constants
const int PRIME_NUMS[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
const long long int INF = 2147483648;

/**
* @brief Generates highly composite numbers.
* @param vec the vector of candidates.
* @param n the max value of the composite number.
* @param idx the current position in PRIME_NUMS array.
* @param maxPower the power limit.
* @param cand the current candidate for the highly composite number.
* @param nDivisors the number of cand's divisors.
*/
void generateCandidates(highlyComposites& vec, int& n, int idx, int maxPower, int cand, int nDivisors);

// https://szkopul.edu.pl/problemset/problem/AB6xXa9zVukjNRe7nvPqxbVQ/site/?key=statement
int main(){
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Initialize variables and DS
    highlyComposites candidates;
    int n, ans=1, dCount=1;

    // Input
    std::cin >> n;

    // Generate candidates for highly composite numbers
    generateCandidates(candidates, n, 0, 31, 1, 1);
    std::sort(candidates.begin(), candidates.end());

    // Go through candidates
    for (auto cand : candidates) {
        
        // Discovered new composite number!!!
        if (cand.second > dCount) {
            ans = cand.first;
            dCount = cand.second;
        }
    }
    
    // Output
    std::cout << ans;

    return 0;
}

void generateCandidates(highlyComposites& vec, int& n, int idx, int maxPower, int cand, int nDivisors) {
    // Save highly composite number
    vec.push_back({ cand, nDivisors });

    // Use greater power p^i
    for (int i = 1; i <= maxPower; i++) {
        long long int newCand = PRIME_NUMS[idx] * (long long int)cand;
        
        // Exceeded the limit
        if (newCand > INF || (int)newCand > n) return;
        if (PRIME_NUMS[idx] > (n / cand)) return;
        
        // Update number
        cand = newCand;
        generateCandidates(vec, n, idx + 1, i, (int)newCand, nDivisors * (i + 1));
    }
}
