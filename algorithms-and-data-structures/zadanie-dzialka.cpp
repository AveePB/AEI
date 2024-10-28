#include <iostream>
#include <stack>

const int MAX_N = 2e3+7;

int maxArea(int* hist, int n) {
    std::stack<std::pair<int, int>> stck; // <idx, height>
    int ans = 0;

    for (int i=0; i<n; i++) {
        int startIdx = i;
        // Try to strech rect area
        while (!stck.empty() && stck.top().second > hist[i]) {
            // Pop from stack
            std::pair<int, int> p = stck.top();
            stck.pop();

            // Strech rect area
            startIdx = p.first;

            // Compute area
            int area = (i - p.first) * p.second;
            ans = std::max(ans, area);
        }

        // Push on stack
        stck.push({startIdx, hist[i]});
    }

    // Handle leftovers
    while (!stck.empty()) {
        // Pop from stack
        std::pair<int, int> p = stck.top();
        stck.pop();

        // Compute area
        int area = (n - p.first) * p.second;
        ans = std::max(ans, area);
    }

    return ans;
}

// https://szkopul.edu.pl/c/oki-olimpiada-dla-zaawansowanych/p/dzi/21768/
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    int n, ans=0, cell, hist[MAX_N];

    // Input
    std::cin >> n;
    for (int i=0; i<n; i++) hist[i] = 0;

    for (int i=0; i<n; i++) {
        // Load entire row
        for (int j=0; j<n; j++) {
            std::cin >> cell;
            hist[j] = (cell == 0) ? hist[j] + 1 : 0;
        }

        // Get largest rect in histogram
        ans = std::max(ans, maxArea(hist, n));
    }

    std::cout << ans;
    
    return 0;
}