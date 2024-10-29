#include <iostream>
#include <string>

typedef std::pair<double, double> fr;

std::string sternBrocotPath(fr w, fr l, fr r) {
    // Compute new fraction
    fr mid = {l.first + r.first, l.second + r.second};

    // Targeted fraction is greater
    if ((mid.first/mid.second) < (w.first/w.second)) 
        return 'P' + sternBrocotPath(w, mid, r); 

    // Targeted fraction is smaller
    else if ((mid.first/mid.second) > (w.first/w.second)) 
        return 'L' + sternBrocotPath(w, l, mid);
    
    // Found targeted fraction
    else
        return "";
}

// https://szkopul.edu.pl/problemset/problem/37RX4_uhWdycW-QFAEztpLbc/site/?key=statement
int main() {
    // Speed boosters 
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    
    // Variables
    int n, m;

    // Input
    std::cin >> n >> m;

    // Output
    std::cout << sternBrocotPath({n, m}, {0, 1}, {1, 0});

    return 0;
}