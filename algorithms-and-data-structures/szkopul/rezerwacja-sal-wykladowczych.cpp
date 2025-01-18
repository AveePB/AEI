#include <iostream>
#include <algorithm>

typedef std::pair<int, int> lec;

const int N = 1e4 + 7;

// Custom lecture comperator
bool compByLectureEnd(lec p1, lec p2) {
    return p1.second < p2.second;
}

int binSearch(lec* lecture, int* dp, int l, int r, int lecStart) {
    // Repeat till 2
    while (r-l > 1) {
        int mid = (r + l) / 2;

        // Lecture collides 
        if (lecture[mid].second > lecStart)
            r = mid;

        // Lecture before current one
        else
            l = mid;
    }

    // Found lecture that starts before current one
    if (lecture[l].second <= lecStart)
        return dp[l];

    return 0;
}

// https://szkopul.edu.pl/problemset/problem/ex8U04OQav3BWcaH7wCtK-_b/site/?key=statement
int main() {
    // Speed boosters
    std::ios_base::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);

    int n, dp[N]; lec lecture[N];

    // Input
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> lecture[i].first >> lecture[i].second;
    
    // Start to analyze
    std::sort(lecture, lecture+n, compByLectureEnd);
    dp[0] = lecture[0].second - lecture[0].first;

    // Run binary search on each 
    for (int i = 1; i < n; i++) {
        // Find best use till current lecture
        dp[i] = lecture[i].second - lecture[i].first;
        dp[i] += binSearch(lecture, dp, 0, i+1, lecture[i].first);

        // Take better time use 
        dp[i] = std::max(dp[i], dp[i - 1]);
    }

    // Maximum time use of room
    std::cout << dp[n - 1];

    return 0;
}
