#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have coins of denominations 5 and 10.
 * To minimize the number of coins, we should use as many 10-rupee coins as possible.
 * 
 * Logic:
 * 1. If X is not divisible by 5, it is impossible to form X using only 5s and 10s. Return -1.
 * 2. If X is divisible by 5:
 *    - We want to maximize the number of 10s.
 *    - Number of 10s = X / 10.
 *    - Remainder = X % 10.
 *    - If remainder is 0, we need (X / 10) coins.
 *    - If remainder is 5, we need (X / 10) + 1 coins (one 5-rupee coin).
 * 
 * This can be simplified:
 * If X % 10 == 0, result is X / 10.
 * If X % 10 == 5, result is (X / 10) + 1.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        if (x % 5 != 0) {
            cout << -1 << "\n";
        } else {
            // Calculate number of 10s
            int coins = x / 10;
            // If there is a remainder of 5, add one 5-rupee coin
            if (x % 10 != 0) {
                coins += 1;
            }
            cout << coins << "\n";
        }
    }

    return 0;
}