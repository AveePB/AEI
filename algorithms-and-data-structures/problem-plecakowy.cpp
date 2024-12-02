#include <iostream>

const int MAX_W = 1e4 + 7;
const int MAX_N = 109 + 7;

// https://szkopul.edu.pl/c/oki-olimpiada-dla-zaawansowanych/p/ple/
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    int n, b, dp[MAX_W], weight[MAX_N], value[MAX_N];
    std::fill_n(dp, MAX_W, 0);

    // Input
    std::cin >> n >> b;
    for (int i=0; i<n; i++) std::cin >> weight[i];
    for (int i=0; i<n; i++) std::cin >> value[i];

    // Analyze values
    for (int i=0; i<n; i++) {

        // Try to pack item into backpack
        for (int w=b; w >= weight[i]; w--)
            dp[w] = std::max(dp[w], dp[w-weight[i]] + value[i]);
    }

    // Output
    std::cout << dp[b] << '\n';

    return 0;
}