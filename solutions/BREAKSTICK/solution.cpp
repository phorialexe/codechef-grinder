#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a stick of length N and want to obtain a stick of length X.
 * The rule is: we can break a stick of length L into k parts (k >= 2) 
 * such that all parts have the same parity.
 * 
 * Case 1: If X is odd.
 * If N is odd, we can always break N into (N-X) and X. Since N and X are both odd,
 * (N-X) is even. This doesn't immediately satisfy the parity rule.
 * However, if N is odd, we can break N into parts of length 1. Since 1 is odd, 
 * we can obtain any odd length X < N.
 * If N is even, we can break N into (N-X) and X. Since N is even and X is odd,
 * (N-X) is odd. Both parts are odd, so this is valid.
 * Thus, if X is odd, the answer is always YES.
 * 
 * Case 2: If X is even.
 * We can only break a stick of length L into parts of the same parity.
 * If we start with N, and we want to reach X (even), we need to ensure that 
 * the parity of N matches the parity of X.
 * If N is even and X is even, we can break N into X and (N-X). Since both are even,
 * this is valid.
 * If N is odd and X is even, we can never reach X because any break of an odd 
 * length stick results in parts that must all be odd. We can never produce an 
 * even length stick from an odd length stick.
 * 
 * Summary:
 * If X is odd: YES
 * If X is even: YES if N is even, NO if N is odd.
 */

void solve() {
    long long N, X;
    cin >> N >> X;

    if (X % 2 != 0) {
        // If X is odd, we can always obtain it
        cout << "YES" << "\n";
    } else {
        // If X is even, we can only obtain it if N is also even
        if (N % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
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