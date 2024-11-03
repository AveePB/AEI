#include <iostream>

typedef std::pair<int, int> fr;

void printSternBrocotTree(fr mid, fr r, int depth);

// https://szkopul.edu.pl/problemset/problem/zFA7joqxZZ9lbwA0FoqjmZwP/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variable
    int n;

    // Generate stern brocot tree
    std::cin >> n;

    std::cout << "0/1 ";
    printSternBrocotTree({0, 1}, {1, 0}, n);
    std::cout << "1/0\n";

    return 0;
}

void printSternBrocotTree(fr l, fr r, int depth) {
    // Reached bottom
    if (depth == 0) return;

    // Get fraction
    fr mid = {l.first+r.first, l.second+r.second};

    // Go to left child
    printSternBrocotTree(l, mid, depth-1);
    
    // Print fraction
    std::cout << mid.first << '/' << mid.second << ' ';

    // Go to right child
    printSternBrocotTree(mid, r, depth-1);
}