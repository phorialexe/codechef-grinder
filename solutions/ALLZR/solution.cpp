#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let x be the number of Type 1 operations performed.
 * Let y be the number of Type 2 operations performed.
 * 
 * The operations are:
 * Type 1: A -> A-1, B -> B-2
 * Type 2: B -> B-1, C -> C-3
 * 
 * After x operations of Type 1 and y operations of Type 2:
 * A_final = A - x
 * B_final = B - 2x - y
 * C_final = C - 3y
 * 
 * We want A_final = 0, B_final = 0, C_final = 0.
 * 
 * From A_final = 0: x = A
 * From C_final = 0: 3y = C => y = C / 3
 * 
 * For a valid solution:
 * 1. x must be equal to A. Since we must perform non-negative operations, A must be >= 0.
 * 2. y must be equal to C / 3. Since y must be an integer, C must be divisible by 3.
 * 3. Substituting x and y into B_final = 0:
 *    B - 2(A) - (C/3) = 0
 *    B = 2A + C/3
 * 
 * So, the conditions are:
 * 1. A >= 0
 * 2. C % 3 == 0
 * 3. B == 2 * A + (C / 3)
 */

void solve() {
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return;

    // Check if C is divisible by 3
    if (C % 3 != 0) {
        cout << "No" << "\n";
        return;
    }

    // Calculate required operations
    long long x = A;
    long long y = C / 3;

    // Check if B matches the requirement
    if (B == 2 * x + y) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}