#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given an array A of length N, we want to maximize A_1 + A_N after any number of right rotations.
 * 
 * Let the original array be A[0], A[1], ..., A[N-1].
 * After k right rotations, the new array starts with A[N-k] and ends with A[N-k-1].
 * Specifically:
 * - 0 rotations: A[0] + A[N-1]
 * - 1 rotation: A[N-1] + A[0] (Same as 0 rotations)
 * - 2 rotations: A[N-2] + A[N-1]
 * - ...
 * - k rotations: A[N-k] + A[N-k-1]
 * 
 * Essentially, after any number of rotations, the pair (A_1, A_N) will always be 
 * either the original (A[0], A[N-1]) or a pair of adjacent elements (A[i], A[i+1]) 
 * for some i from 0 to N-2.
 * 
 * So we need to find the maximum of:
 * 1. A[0] + A[N-1]
 * 2. A[i] + A[i+1] for all 0 <= i < N-1
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the array.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Initialize max_sum with the case of 0 rotations
    long long max_sum = A[0] + A[N - 1];

    // Check all adjacent pairs (A[i], A[i+1])
    for (int i = 0; i < N - 1; ++i) {
        long long current_sum = A[i] + A[i + 1];
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    cout << max_sum << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}