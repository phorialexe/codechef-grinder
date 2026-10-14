#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence of 0s and 1s representing a queue.
 * We need to ensure that for any two people (1s), the distance between them is at least 6.
 * If the indices of two people are i and j (where i < j), the distance is (j - i).
 * The condition is (j - i) >= 6.
 * 
 * Algorithm:
 * 1. Iterate through the array and keep track of the index of the last person seen.
 * 2. Initialize last_pos = -10 (a value small enough so that the first person doesn't trigger a false violation).
 * 3. For each index i where A[i] == 1:
 *    - If (i - last_pos) < 6, then social distancing is violated. Return "NO".
 *    - Update last_pos = i.
 * 4. If we finish the loop without violations, return "YES".
 * 
 * Complexity:
 * Time: O(N) per test case, where N <= 100. Total O(T * N).
 * Space: O(N) to store the array, or O(1) if processed on the fly.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int last_pos = -10; // Initialize with a value that ensures the first person is safe
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            if (i - last_pos < 6) {
                possible = false;
                break;
            }
            last_pos = i;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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