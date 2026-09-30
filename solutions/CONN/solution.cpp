#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find if N = 2X + 7Y for non-negative integers X, Y.
 * This is a variation of the Frobenius Coin Problem (or Change-making problem).
 * Since we have 2 and 7, we can represent any number N as long as N is not 
 * too small or specifically impossible.
 * 
 * Specifically:
 * - If N is even, we can always represent it as 2*X (Y=0).
 * - If N is odd, we need at least one 7 (Y >= 1).
 *   If we use one 7, the remaining value is N - 7.
 *   If (N - 7) >= 0 and (N - 7) is even, then we can represent N as 7*1 + 2*X.
 * 
 * So, for any N:
 * 1. If N < 0, impossible.
 * 2. If N == 1, 3, 5, impossible.
 * 3. Otherwise, it is always possible.
 *    - Even numbers: 2, 4, 6, 8... (Y=0)
 *    - Odd numbers: 7, 9, 11, 13... (Y=1, then N-7 is even)
 * 
 * The impossible values are 1, 3, 5.
 */

void solve() {
    long long N;
    cin >> N;

    if (N == 1 || N == 3 || N == 5) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
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