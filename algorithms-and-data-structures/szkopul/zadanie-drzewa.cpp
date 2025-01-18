#include <iostream>
#include <string>
#include <vector>

const int MAX_N = 2500 + 7;
const int NONE = -1;

// Global data structures
int leaf[MAX_N], tree[2*MAX_N][2];

// Functions
void constructTree(int& node, int& ptr, int n, int depth);
void printGenealogicalForm(int& node, int prevNode);
void printBracketForm(int& node);

// https://szkopul.edu.pl/problemset/problem/7-HJKUXJXg7Fcq0WLy5i1hhT/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    int n, ptr=0, node=1;

    // Load level representation
    std::cin >> n;
    for (int i = 0; i < n; i++) 
        std::cin >> leaf[i];

    // Initialize & generate tree
    for (int i=0; i<2*MAX_N; i++) 
        tree[i][0] = tree[i][1] = NONE;

    constructTree(node, ptr, n, 0);

    // Failed to construct tree
    if (ptr < n) {
        std::cout << "NIE\n";
    } 

    // Tree was successfully constructed
    else {
        // Genealogical representation
        node = 1;
        printGenealogicalForm(node, 0);
        std::cout << '\n';

        // Bracket representation
        node = 1;
        printBracketForm(node);
    }

    return 0;
}

void constructTree(int& node, int& ptr, int n, int depth) {
    // Check bounds
    if (ptr >= n) return;

    // Save info
    int currNode = node;

    // Current node is leaf
    if (depth == leaf[ptr]) {
        ptr++;
        return;
    }

    // Tree got too deep
    else if (depth > leaf[ptr]) {
        return;
    }

    // Go to left child
    if (ptr < n && depth+1 <= leaf[ptr]) {
        tree[currNode][0] = ++node;
        constructTree(node, ptr, n, depth+1);
    }

    // Go to right child
    if (ptr < n && depth+1 <= leaf[ptr]) {
        tree[currNode][1] = ++node;
        constructTree(node, ptr, n, depth+1);
    }
}

void printGenealogicalForm(int& node, int prevNode) {
    std::cout << prevNode << ' ';
    int currNode = node;

    // Go to left son
    if (tree[currNode][0] != -1)
        printGenealogicalForm(++node, currNode);

    // Go to right son
    if (tree[currNode][1] != -1)
        printGenealogicalForm(++node, currNode);
}

void printBracketForm(int& node) {
    std::cout << '(';
    int currNode = node;

    // Go to left son
    if (tree[currNode][0] != -1)
        printBracketForm(++node);

    // Go to right son
    if (tree[currNode][1] != -1)
        printBracketForm(++node);

    std::cout << ')';
}
