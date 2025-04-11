#include <algorithm>
#include <iostream>
#include <queue>

const int UNSET = 2137e3 + 7;
const int WHITE = '1';
const int N = 182 + 7;
const int M = 182 + 7;

// https://szkopul.edu.pl/problemset/problem/fIwYfy0zzmVZJJXTShFq2ICC/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    std::queue<std::pair<int, int>> q;
    int n, m, dist[N][M];

    // Load the bitmap
    std::cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char pixel;
            std::cin >> pixel;
            dist[i][j] = UNSET;

            if (pixel == WHITE) {
                q.push({ i, j });
                dist[i][j] = 0;
            }
        }
    }

    // Analyze neighboring pixels
    while (!q.empty()) {
        // Access first element
        std::pair<int, int> pixel = q.front();
        int row = pixel.first, col = pixel.second;
        q.pop();

        // Check left pixel
        if (0 <= col - 1 && dist[row][col - 1] == UNSET) {
            dist[row][col - 1] = 1 + dist[row][col];
            q.push({ row, col - 1 });
        }

        // Check right pixel
        if (col + 1 < m && dist[row][col + 1] == UNSET) {
            dist[row][col + 1] = 1 + dist[row][col];
            q.push({ row, col + 1 });
        }

        // Check top pixel
        if (row - 1 >= 0 && dist[row - 1][col] == UNSET) {
            dist[row - 1][col] = 1 + dist[row][col];
            q.push({ row - 1, col });
        }

        // Check bottom pixel
        if (row + 1 < n && dist[row + 1][col] == UNSET) {
            q.push({ row + 1, col });
            dist[row + 1][col] = 1 + dist[row][col];
        }
    }

    // Output matrix of distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            std::cout << dist[i][j] << ' ';
        std::cout << '\n';
    }

    return 0;
}