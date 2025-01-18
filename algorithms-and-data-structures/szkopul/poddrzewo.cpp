#include <iostream>

// https://szkopul.edu.pl/problemset/problem/w9_OeHLYqjDZ3e_0QBG8Fj1U/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    int n, v, x=0, ones=0;

    // Load vertice degrees (count ones)
    std::cin >> n;
    for (int i=0; i<n; i++) {
        std::cin >> v;
        if (v == 1) ones++;
    }

    // Analyze counter
    if (ones < 2)
        x = 2 - ones; 

    // Output
    std::cout << x << '\n';
    std::cout << 2 << '\n';
    std::cout << "1 2\n";

    return 0;
}