#include <iostream>

// Constants
const int MAX_AGE = 2020;
const int N = 2e3+7;

// https://szkopul.edu.pl/problemset/problem/T-F5dZGgu3pmKAzGdWUfoHy6/site/?key=statement
int main() {
	// Speed boosters
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	// Variables
	int n, k, wine[N][N], cost[N][N];
	std::cin >> n >> k;
	for (int i = 0; i <= n; i++) std::fill_n(cost[i], N, 0);

	// Read wine age
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			std::cin >> wine[i][j];
			cost[i][j] = cost[i - 1][j] + j;
		}
	}

	// Find greatest age for king
	int greatestAge = MAX_AGE;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			// Bottle in reach
			if (cost[i][j] <= k)
				greatestAge = std::min(greatestAge, wine[i][j]);
		}
	}

	// Output
	std::cout << greatestAge;

	return 0;
}