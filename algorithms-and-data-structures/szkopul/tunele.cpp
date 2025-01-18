#include <iostream>
#include <map>

const int MAX_SIZE = 5e5 + 7;
const int INF = 1e9 + 7;

int revBinSearch(int* t, int n, int car);

// https://szkopul.edu.pl/problemset/problem/OCCMf-wmXSSDpoa6G54rwXwV/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    int a, b, c, t[MAX_SIZE]; t[0] = INF;

    // Input 
    std::cin >> a >> b;

    // Load tunnels
    for (int i=0; i<a; i++) {
        std::cin >> t[i+1];
        t[i+1] = std::min(t[i+1], t[i]);
    }

    // Handle queries
    for (int i=0; i<b; i++) {
        std::cin >> c;
        std::cout << revBinSearch(t, a+1, c) - 1 << ' ';
    }

    return 0;
}

int revBinSearch(int* t, int n, int target) {
    int low = 0, high = n-1, ans = 0;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Car doesn't fit into tunnel
        if (t[mid] <= target) {
            high = mid - 1;
        }
        // Car fits into tunnel
        else {
            low = mid + 1;
        }
    }

    return low;
}