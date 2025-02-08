#include <iostream>
#include <vector>

const int MAX_SIZE = 1e3 + 7;

// https://szkopul.edu.pl/problemset/problem/UU2Uj-barjiONnRxd9aEVoDj/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    std::vector<int> grayEdges[MAX_SIZE];
    int a, b, n, m;

    // Compute total number of triangles
    std::cin >> n >> m;
    int nTriangles = n * (n - 1) * (n - 2) / 6;

    // Construct graph
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        grayEdges[a].push_back(b);
        grayEdges[b].push_back(a);
    }

    // Count diffrently colored triangles
    int nDiffColoredTriangles = 0;
    for (int i = 1; i <= n; i++) {
        // Get number of gray edges
        int k = grayEdges[i].size();
        nDiffColoredTriangles += k * (n - 1 - k);
    }

    // We counted them twice
    nDiffColoredTriangles /= 2;

    // Total number of one colored triangles
    std::cout << nTriangles - nDiffColoredTriangles;

    return 0;
}
