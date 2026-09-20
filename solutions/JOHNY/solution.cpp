#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array of N song lengths. We know the initial position K of "Uncle Johny".
 * We need to find the new position of "Uncle Johny" after the array is sorted in non-decreasing order.
 * 
 * Approach:
 * 1. Store the value of the song at index K-1 (since input is 1-indexed).
 * 2. Sort the array of song lengths.
 * 3. Find the position of the stored value in the sorted array.
 * 4. Since all song lengths are unique, the position is unique.
 * 
 * Complexity:
 * Time: O(T * N log N) where T is number of test cases and N is number of songs.
 * Given N <= 100 and T <= 1000, this is well within the 2.5s time limit.
 * Space: O(N) to store the array.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int k;
    cin >> k;
    
    // The length of "Uncle Johny"
    long long uncle_johnny_len = a[k - 1];
    
    // Sort the playlist
    sort(a.begin(), a.end());
    
    // Find the new position (1-indexed)
    for (int i = 0; i < n; ++i) {
        if (a[i] == uncle_johnny_len) {
            cout << (i + 1) << "\n";
            return;
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}