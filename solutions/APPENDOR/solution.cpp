#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S = A_1 | A_2 | ... | A_N.
 * We need to find the minimum X such that (S | X) = Y.
 * 
 * Properties of Bitwise OR:
 * 1. If any bit is set in S but not in Y, it is impossible to reach Y by ORing X, 
 *    because ORing can only turn bits from 0 to 1, never 1 to 0.
 *    Condition: (S & Y) must be equal to S. Or equivalently, (S | Y) == Y.
 * 2. If the condition holds, we need (S | X) = Y.
 *    To minimize X, we should only set the bits in X that are in Y but not in S.
 *    X = Y & (~S).
 * 
 * Complexity:
 * Time: O(N) per test case to compute S.
 * Space: O(1) auxiliary space (excluding input storage).
 */

void solve() {
    int N;
    long long Y;
    cin >> N >> Y;
    
    long long current_or = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        current_or |= a;
    }
    
    // Check if current_or is a subset of Y
    // If (current_or | Y) != Y, it means there is a bit set in current_or 
    // that is not set in Y. Since OR only adds bits, we can't reach Y.
    if ((current_or | Y) != Y) {
        cout << -1 << "\n";
    } else {
        // We need X such that (current_or | X) == Y.
        // To minimize X, we take the bits that are in Y but not in current_or.
        long long X = (Y ^ current_or);
        cout << X << "\n";
    }
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