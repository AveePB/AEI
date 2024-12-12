#include <iostream>
#include <vector>

// Constants 
const int N = 1e5 + 7;
const int NONE = -1;

// Functions declarations;
std::pair<int, int> detect_cycle(std::vector<std::vector<int>>& graph, bool* vis, int prevV, int currV);
void assignEdges(std::vector<std::vector<int>>& graph, int* ans, int prevV, int currV);

// https://szkopul.edu.pl/problemset/problem/ptF7RsWMiiMdzzZWt5BKFAnT/site/?key=statement
int main() {
	// Speed boosters
	std::ios_base::sync_with_stdio(0);
	std::cout.tie(0);
	std::cin.tie(0);

	// Variables
	int n, m;
	std::cin >> n >> m;
	
	// Initialize structures
	std::vector<std::vector<int>> graph(n);
	int ans[N]; bool vis[N];
	std::fill_n(ans, n, NONE);
	std::fill_n(vis, n, false);

	// Create connections between vertices
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		graph[a - 1].push_back(b - 1);
		graph[b - 1].push_back(a - 1);
	}

	// Go through all vertice
	for (int v = 0; v < n; v++) {
		// Cycle already visited
		if (ans[v] != NONE) continue;

		// Check if cycle
		std::pair<int, int> cycle = detect_cycle(graph, vis, v, v);
		int startV = cycle.first, endV = cycle.second;

		// Decree check (unsolvable)
		if (startV == -1 || endV == -1) {
			std::cout << "NIE\n";
			return 0;
		}

		// Swap last value with `endV` in graph[startV]
		for (int i = 0; i < graph[startV].size(); i++)
			if (graph[startV][i] == endV)
				std::swap(graph[startV][i], graph[startV].back());
		

		// Swap last value with `startV` in graph[endV]
		for (int i = 0; i < graph[endV].size(); i++)
			if (graph[endV][i] == startV)
				std::swap(graph[endV][i], graph[endV].back());
		
		// Remove last elements from graph[startV] & graph[endV]
		graph[startV].pop_back();
		graph[endV].pop_back();

		assignEdges(graph, ans, startV, startV);
		ans[startV] = endV;
	}

	// Output
	std::cout << "TAK\n";
	for (int i = 0; i < n; i++)
		std::cout << ans[i] + 1 << '\n';
}

// Function returns the begining & the end of the cycle
std::pair<int, int> detect_cycle(std::vector<std::vector<int>>& graph, bool* vis, int prevV, int currV) {
	// Cycle has been detected
	if (vis[currV])	return { currV, prevV };
	vis[currV] = true;

	// Check out neighbours
	for (int nextV : graph[currV]) {
		if (nextV == prevV) continue;
		std::pair<int, int> ans = detect_cycle(graph, vis, currV, nextV);

		// Detcted cycle
		if (ans.first != -1 && ans.second != -1) return ans;
	}
	
	return { -1, -1 };
}

// Function that assigns edges to their vertices
void assignEdges(std::vector<std::vector<int>>& graph, int* ans, int prevV, int currV) {
	// Edge is already assigned
	if (ans[currV] != NONE) return;

	ans[currV] = prevV;

	// Check out neighbours
	for (int nextV : graph[currV])
		assignEdges(graph, ans, currV, nextV);
}

