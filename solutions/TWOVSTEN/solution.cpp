#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make X divisible by 10.
 * A number is divisible by 10 if its last digit is 0.
 * 
 * Let's look at the last digit of X:
 * - If X % 10 == 0: Already divisible, 0 turns.
 * - If X % 10 == 5: 
 *      5 * 2 = 10 (divisible by 10), 1 turn.
 * - Any other last digit (1, 2, 3, 4, 6, 7, 8, 9):
 *      - If last digit is 2: 2*2=4, 4*2=8, 8*2=16, 6*2=12... never ends in 0.
 *      - If last digit is 1: 1*2=2, 2*2=4, 4*2=8, 8*2=16, 6*2=12... never ends in 0.
 *      - Basically, if the last digit is not 0 or 5, multiplying by 2 will never result in a 0.
 * 
 * Logic:
 * 1. If X % 10 == 0, return 0.
 * 2. If X % 10 == 5, return 1.
 * 3. Otherwise, return -1.
 */

void solve() {
    long long X;
    cin >> X;
    
    if (X % 10 == 0) {
        cout << 0 << "\n";
    } else if (X % 5 == 0) {
        // Since it's not divisible by 10 but is divisible by 5, 
        // the last digit must be 5. Multiplying by 2 makes it end in 0.
        cout << 1 << "\n";
    } else {
        cout << -1 << "\n";
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