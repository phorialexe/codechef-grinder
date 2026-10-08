#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts with brick 1.
 * He iterates through bricks 2 to N.
 * If the current brick (index i) has a size A[i] strictly greater than the size of the brick he is holding,
 * he updates his current brick to index i.
 * 
 * Complexity:
 * Time: O(N) per test case, where N is the number of bricks.
 * Space: O(N) to store the brick sizes.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Chef starts with brick 1 (index 0 in 0-based array)
    int current_brick_idx = 0;
    int current_size = A[0];
    
    // Iterate through bricks 2 to N (indices 1 to N-1)
    for (int i = 1; i < N; ++i) {
        if (A[i] > current_size) {
            current_size = A[i];
            current_brick_idx = i;
        }
    }
    
    // Output the 1-based index of the final brick
    cout << (current_brick_idx + 1) << "\n";
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