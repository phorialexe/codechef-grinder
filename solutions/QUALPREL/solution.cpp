#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N scores and a threshold K.
 * We need to find the number of teams that qualify.
 * A team qualifies if its score is >= the score of the K-th team 
 * when the scores are sorted in descending order.
 * 
 * Algorithm:
 * 1. Sort the array of scores in descending order.
 * 2. Identify the score at index K-1 (0-indexed). Let this be threshold_score.
 * 3. Count how many scores in the array are >= threshold_score.
 * 
 * Complexity:
 * Sorting takes O(N log N).
 * Counting takes O(N).
 * Total time complexity: O(N log N) per test case.
 * Given the sum of N over test cases is 10^6, this fits well within the 1s time limit.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<long long> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    
    // Sort in descending order
    sort(S.begin(), S.end(), greater<long long>());
    
    // The K-th team is at index K-1
    long long threshold = S[K - 1];
    
    // Count how many teams have score >= threshold
    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] >= threshold) {
            count++;
        } else {
            // Since the array is sorted descending, we can break early
            break;
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}