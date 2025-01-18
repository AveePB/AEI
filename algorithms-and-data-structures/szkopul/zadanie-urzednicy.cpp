#include <iostream>

const int N = 1e6+7;

// https://szkopul.edu.pl/problemset/problem/cSV0kK7zLib42_NGIA7DvOoZ/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Initialize variables
    int n, nReports=0, arr[N], dp[N];
    std::fill_n(dp, N, 0);
    arr[0] = 0;

    // Input
    std::cin >> n;
    for (int i=1; i<n; i++) {
        std::cin >> arr[i];
        arr[i]--;
    }

    // Go through company employees
    for (int i=n-1; i>0; i--) {
        // Update boss's employee count
        if (dp[i] == 0) {
            dp[arr[i]] += 1;
        }

        // Move boss's employees to supervisor
        else {
            dp[arr[i]] += dp[i] - 1;
            dp[i] = 1; // Safety (report)
        }
    }

    // Count secured positions 
    for (int i=0; i<n; i++)
        if (dp[i] > 0) nReports++;
    
    // Output
    std::cout << nReports;

    return 0;
}
