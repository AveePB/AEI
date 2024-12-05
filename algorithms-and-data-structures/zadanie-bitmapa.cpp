#include <iostream>
#include <queue>

// Constant
const int N = 182 + 7;
const int INF = 1e6+7;

// https://szkopul.edu.pl/problemset/problem/fIwYfy0zzmVZJJXTShFq2ICC/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    std::queue<std::pair<int, int>> bfs;
    int n, m, dist[N][N];
    char c;

    // Initialize distances
    for (int i=0; i<N; i++) 
        for (int j=0; j<=N; j++)
            dist[i][j] = INF;

    // Input
    std::cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            std::cin >> c;

            // New start point
            if (c == '1') {
                dist[i][j] = 0;
                bfs.push({i, j});
            }
        }
    }

    // Breadth-first search
    while (!bfs.empty()) {
        // Get current position
        std::pair<int, int> pos = bfs.front();
        bfs.pop(); 
        
        // Boundaries check
        int x = pos.first, y = pos.second;
        if (x < 1 || x > n || y < 1 || y > m) continue;

        // Check left cell
        if (dist[x-1][y] > 1 + dist[x][y]) {
            dist[x-1][y] = 1 + dist[x][y];
            bfs.push({x-1, y}); 
        }

        // Check right cell
        if (dist[x+1][y] > 1 + dist[x][y]) {
            dist[x+1][y] = 1 + dist[x][y];
            bfs.push({x+1, y}); 
        }

        // Check top cell
        if (dist[x][y-1] > 1 + dist[x][y]) {
            dist[x][y-1] = 1 + dist[x][y];
            bfs.push({x, y-1}); 
        }

        // Check bottom cell
        if (dist[x][y+1] > 1 + dist[x][y]) {
            dist[x][y+1] = 1 + dist[x][y];
            bfs.push({x, y+1}); 
        }
    }

    // Output
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++)
            std::cout << dist[i][j] << ' ';
        std::cout << '\n';
    }

    return 0;
}