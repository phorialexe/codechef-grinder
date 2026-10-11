#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To make the permutation "End Sorted", we need P[1] = 1 and P[N] = N.
 * We can move 1 to the first position and N to the last position using adjacent swaps.
 * 
 * Let the initial index of 1 be idx1 (0-indexed) and the initial index of N be idxN (0-indexed).
 * 
 * 1. To move 1 to index 0:
 *    It takes 'idx1' swaps.
 * 2. To move N to index N-1:
 *    It takes '(N - 1) - idxN' swaps.
 * 
 * However, if idx1 > idxN, the swap that moves 1 to the left will also move N to the right 
 * (or vice versa), effectively reducing the total count by 1 because they cross each other.
 * 
 * Total operations = (idx1) + (N - 1 - idxN) - (1 if idx1 > idxN else 0)
 */

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    int idx1 = -1, idxN = -1;
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
        if (P[i] == 1) {
            idx1 = i;
        } else if (P[i] == N) {
            idxN = i;
        }
    }

    // Operations to move 1 to index 0: idx1
    // Operations to move N to index N-1: (N - 1 - idxN)
    // If idx1 > idxN, they swap positions at some point, saving one operation.
    int ops = idx1 + (N - 1 - idxN);
    if (idx1 > idxN) {
        ops -= 1;
    }

    cout << ops << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}