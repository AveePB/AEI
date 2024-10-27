#include <iostream>
#include <vector>

const int MAX_N = 3e4 + 7;

void markCycle(bool* marked, int* graph, int v) {
    // Vertice is already marked
    if (marked[v]) return;

    // Mark new vertice
    marked[v] = true;
    markCycle(marked, graph, graph[v]);
}

// https://szkopul.edu.pl/problemset/problem/NQamRQ2UZEwn6gPqo-l6nat9/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    int n, count=0, graph[MAX_N];
    bool marked[MAX_N];

    // Input
    std::cin >> n;

    // Load guests
    for (int i=1; i<=n; i++) {
        std::cin >> graph[i];
        marked[i] = false;
    }

    // Detect graph cycles
    for (int i=1; i<=n; i++) {
        // Vertice is already marked
        if (marked[i]) continue;

        // Detected new cycle
        count += 1;
        markCycle(marked, graph, i);
    }

    std::cout << count;

    return 0;
}