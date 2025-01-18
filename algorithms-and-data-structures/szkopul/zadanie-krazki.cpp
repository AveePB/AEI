#include <iostream>
#include <vector>
#include <map>

const int INF = 1e9 + 7;

void throw_disk(std::vector<int>& tubes, int& ans, int disk) {
    for (int i=ans-1; i>0; i--) {
        // Disk doesn't fit
        if (tubes[i] < disk) continue; 
        
        // Disk landed
        ans = i;
        return;
    }
    ans = 0;
}

// https://szkopul.edu.pl/problemset/problem/fYXVXOreVxlXTRoHZJXyXF2l/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    std::vector<int> tubes; tubes.push_back(INF);
    int n, m, t, d, ans;

    // Input
    std::cin >> n >> m;
    ans = n + 1;

    // Load tubes
    for (int i=0; i<n; i++) {
        std::cin >> t;
        t = std::min(t, tubes.back());

        tubes.push_back(t);
    }

    // Play with disks
    for (int i=0; i<m; i++) {
        std::cin >> d;
        throw_disk(tubes, ans, d);
    }

    std::cout << ans;

    return 0;
}