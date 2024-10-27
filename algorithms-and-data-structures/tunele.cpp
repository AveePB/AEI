#include <iostream>
#include <map>

const int MAX_SIZE = 1e5 + 7;
const int INF = 1e9 + 7;

// https://szkopul.edu.pl/problemset/problem/OCCMf-wmXSSDpoa6G54rwXwV/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    std::map<int, int> indices; indices.insert({INF, 0});
    int* t = new int[MAX_SIZE]; t[0] = INF;
    int a = 0, b = 0, ptr = 0;

    // Input
    std::cin >> a >> b;

    // Load tunels
    for (int i=1; i<=a; i++) {
        // Get required height
        std::cin >> t[ptr+1];
        t[ptr+1] = std::min(t[ptr+1], t[ptr]);

        // Save tunnel index
        if (indices.find(t[ptr+1]) == indices.end())
            indices[t[++ptr]] = i;
        else 
            indices[t[ptr+1]] =  i;
    }
    
    // Load cars
    for (int i=1; i<=b; i++) {
        int car, max_height;
        std::cin >> car;
    
        // Drive through highway
        for (int i=0; i<=ptr; i++) {
            // Car cannot fit into tunnel
            if (car >= t[i]) break;

            // Car fits into tunnel
            max_height = t[i];
        }
        std::cout << indices.at(max_height) << ' ';
    }
    delete [] t;

    return 0;
}