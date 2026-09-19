#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N horses with skill levels S[i]. We need to find the minimum 
 * absolute difference between any two horses.
 * 
 * Approach:
 * 1. If we sort the array of skills, the minimum difference must exist between
 *    two adjacent elements in the sorted array.
 * 2. Sorting takes O(N log N).
 * 3. Iterating through the sorted array to find the minimum difference takes O(N).
 * 4. Total time complexity per test case: O(N log N).
 * 5. Given N <= 5000 and T <= 10, O(T * N log N) is well within the 1.5s limit.
 * 6. Use long long for skill values to prevent any potential overflow, 
 *    though int suffices for 10^9.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> S(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    
    // Sort the skills to bring the closest values next to each other
    sort(S.begin(), S.end());
    
    // Initialize min_diff with a large value
    long long min_diff = LLONG_MAX;
    
    // Compare adjacent elements
    for (int i = 0; i < N - 1; ++i) {
        long long diff = S[i + 1] - S[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    
    cout << min_diff << "\n";
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