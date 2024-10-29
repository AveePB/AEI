#include <iostream>
#include <vector>
#include <map>

typedef std::map<int, std::vector<int>> ds;

int modBinSearch(std::vector<int>& v, int target);
bool isPossible(ds& memo, std::vector<int>& vec);

// https://szkopul.edu.pl/problemset/problem/Ak4wWPkNtHpF-OiulN1gixfW/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    // Variables
    int a, m, n, mi;
    ds memo;

    // Load series
    std::cin >> m;

    for (int i=0; i<m; i++) {
        std::cin >> a;
        
        // Create list of indexes
        if (memo.find(a) == memo.end())
            memo[a] = std::vector<int>();
        
        memo[a].push_back(i);
    }

    // Handle quests
    std::cin >> n;

    while (n--) {
        // Load subseries
        std::cin >> mi;
        std::vector<int> vec(mi);

        for (int i=0; i<mi; i++) 
            std::cin >> vec[i];
        
        if (isPossible(memo, vec))
            std::cout << "TAK\n";
        else
            std::cout << "NIE\n";
    }

    return 0;
}


int modBinSearch(std::vector<int>& v, int target) {
    // Variables
    int ans = 0, low = 0, high = v.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        // Middle is lesser than target
        if (v[mid] <= target) {
            low = mid + 1;
        }
        // Middle is greater than target
        else {
            ans = mid;
            high = mid - 1;
        }
    }

    return v[ans];
}

bool isPossible(ds& memo, std::vector<int>& vec) {
    int currIdx = -1;

    // Check for each number
    for (int num: vec) {
        // No such element in series
        if (memo.find(num) == memo.end())
            return false;

        // Update index
        int nextIdx = modBinSearch(memo[num], currIdx);
        if (nextIdx <= currIdx) return false;
        currIdx = nextIdx;
    }
    return true;
}
