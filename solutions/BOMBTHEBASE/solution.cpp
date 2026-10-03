#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N houses with defense strengths A_1, A_2, ..., A_N.
 * A bomb with strength X destroys house i if A_i < X.
 * If house i is destroyed, all houses j where 1 <= j <= i are destroyed.
 * To maximize the number of destroyed houses, we need to find the largest index i
 * such that A_i < X. If such an index exists, the number of destroyed houses is i.
 * If no such house exists, the answer is 0.
 * 
 * Complexity:
 * Time: O(N) per test case, O(sum of N) total.
 * Space: O(1) auxiliary space (excluding input storage).
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    
    int max_index = 0;
    for (int i = 1; i <= N; ++i) {
        long long A;
        cin >> A;
        // If the current house can be destroyed by the bomb,
        // it is a candidate for the rightmost house destroyed.
        if (A < X) {
            max_index = i;
        }
    }
    
    cout << max_index << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}