#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

const int MAX_N = 3e3 + 7;

/**
* Computes the hash of a given word. The formula is to sum each letter (raised to power of 4).
* @param w the word.
* @returns numeric value of hash.
*/
long long int createHash(std::string& w) {
    long long int hash = 0;

    // Go through word
    for (char c : w) {
        hash += (long long int)(c) * 
            (long long int)(c) *
            (long long int)(c) *
            (long long int)(c);
        // hash += c^4
    }

    return hash;
}


// https://szkopul.edu.pl/problemset/problem/Aq-3LEQBYOdbiqQXvn3TJ0Id/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    std::map<long long int, std::set<std::string>> ana;
    std::vector<std::pair<std::string, long long int>> hashOrder;
    std::string word[MAX_N];
    int n; 

    // Input
    std::cin >> n;
    for (int i = 0; i < n; i++) std::cin >> word[i];

    // Group words by hashes
    for (int i = 0; i < n; i++) {
        long long int hash = createHash(word[i]);
        ana[hash].insert(word[i]);
    }

    // Order hashes by first element of set
    for (auto& el : ana) {
        std::string firstWord = *el.second.begin();
        long long int hash = el.first;

        hashOrder.push_back({ firstWord, hash });
    }
    std::sort(hashOrder.begin(), hashOrder.end());

    // Output
    for (auto& el : hashOrder) {
        long long int hash = el.second;

        // Print class of anagram
        for (std::string w : ana[hash]) 
            std::cout << w << ' ';
        std::cout << '\n';
    }
    
    return 0;
}
