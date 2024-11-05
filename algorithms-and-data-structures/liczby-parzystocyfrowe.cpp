#include <iostream>
#include <algorithm>
#include <string>

using namespace std; 

std::string evenDigitNumber(long long n) {
    // Variables
    long long currN = n; 
    std::string ans = "";

    // Convert to 5-based numeral system
    while (currN) {
        // Compute rest & divide
        long long rest = currN % 5;
        currN /= 5; 

        // Update answer
        ans += std::to_string(rest*2);
    }

    // Make adjustments
    std::reverse(ans.begin(), ans.end());
    return ans;    
}

// https://szkopul.edu.pl/problemset/problem/g8UTPdAfFtio16W9-8q9hlt-/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variable
    long long n = 0; 
    
    // Find wanted number
    std::cin >> n;
    std::cout << evenDigitNumber(n);
    
    return 0; 
}