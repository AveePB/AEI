#include <iostream>
#include <sstream>
#include <string.h>
const int MAX_LEN = 1e6 + 7;

// https://szkopul.edu.pl/problemset/problem/POAyCWzUB990_g4_MA4GF9Jw/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    std::stringstream ans;
    char c[MAX_LEN];
    int n;

    // Read length
    std::cin >> n;
    c[0] = '#';
    
    // Process characters
    for (int i = 1; i < n; i++) {
        std::cin >> c[i];

        // Opening bracket '('
        if (c[i - 1] == '-' && c[i] == '+') ans << '(';

        // Closing bracket ')'
        else if (c[i - 1] == '+' && c[i] == '-') ans << ')';

        // Minus
        ans << '-';
    }

    // Missing closing bracket ')'
    if (c[n - 1] == '+') ans << ')';

    std::cout << ans.str();

    return 0;
}
