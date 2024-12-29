#include <iostream>

const int N = 1e6 + 7;

// https://szkopul.edu.pl/problemset/problem/LYv3GgRJE475pdAP5SrfSjvW/site/?key=statement
int main() {
	// Speed boosters
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	// Variables
	bool car[N];
	long long int n, totalCount = 0, currCount = 0;
	
	// Read car info
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> car[i];

	while (n--) {
		// Car was missed
		if (car[n])
			currCount++;
		else
			totalCount += currCount;
	}

	std::cout << totalCount;

	return 0;
}
