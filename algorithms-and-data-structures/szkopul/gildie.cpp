#include <iostream>
#include <vector>

// Constants
const int K = 2;
const int S = 1;
const int EMPTY = -1;

// Places guilds in each city to hold the balance
void placeGuild(std::vector<std::vector<int>>& graph, std::vector<int>& guilds, int v, int g);

// https://szkopul.edu.pl/problemset/problem/Oys6jiVOIap59lYCHRwDMbNT/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Initialize variables
    bool isValid = true;
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> graph(n);
    std::vector<int> guilds(n, EMPTY);

    // Construct graph
    for (int i=0; i<m; i++) {
        int a, b;
        std::cin >> a >> b;
        a--; b--;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Analyze each vertex
    for (int v=0; v<n; v++) {
        // City doesn't have roads
        if (graph[v].empty()) {
            isValid = false;
            break;
        }

        // City doesn't have guild
        if (guilds[v] == EMPTY)
            placeGuild(graph, guilds, v, K);
    }

    // Graph is solvable
    if (isValid) {
        std::cout << "TAK\n";
        for (int g: guilds)
            std::cout << ((g == K) ? 'K' : 'S') << '\n';
    }
    else {
        std::cout << "NIE\n";
    }

    return 0;
}

void placeGuild(std::vector<std::vector<int>>& graph, std::vector<int>& guilds, int v, int g) {
    // City was analyzed    
    if (guilds[v] != EMPTY) 
        return;
    
    // Set new guild
    guilds[v] = g;

    // Go to neighboring cities
    for (int nextV: graph[v]) {
        if (g == K)
            placeGuild(graph, guilds, nextV, S);
        else
            placeGuild(graph, guilds, nextV, K);
    }
}