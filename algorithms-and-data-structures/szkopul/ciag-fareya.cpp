#include <iostream>

typedef std::pair<int, int> el;

/**
 * Prints out the farey sequence elements
 * @param l the left bound values 
 * @param r the righ bound values
 * @param lim the limit value
 */
void printFareySequence(el l, el r, int& lim);

// https://szkopul.edu.pl/problemset/problem/XCivS2hfBhDPLj18nL8SJT2f/site/?key=statement
int main() {
	// Speed boosters
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);
	
	// Input
	int n;
	std::cin >> n;

	// Output
	std::cout << "0/1 ";
	printFareySequence({ 0, 1 }, { 1, 1 }, n);
	std::cout << "1/1 ";

	return 0;
}

void printFareySequence(el l, el r, int& lim) {
	// Compute new element
	el m = { l.first + r.first, l.second + r.second };

	// Element doesn't meet the criteria
	if (m.first > m.second || m.first > lim || m.second > lim) return;

	printFareySequence(l, m, lim);
	std::cout << m.first << '/' << m.second << ' ';
	printFareySequence(m, r, lim);
}
