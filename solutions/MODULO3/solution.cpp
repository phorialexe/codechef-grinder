#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two numbers A and B. We want to reach a state where A % 3 == 0 or B % 3 == 0.
 * Let a = A % 3 and b = B % 3.
 * The operations are:
 * 1. A = |A - B|  => new_a = |a - b| % 3
 * 2. B = |A - B|  => new_b = |a - b| % 3
 * 
 * Possible states (a, b) where a, b in {0, 1, 2}:
 * - If a == 0 or b == 0: 0 operations.
 * - If a == b: 
 *      Operation 1: a becomes |a - a| = 0. (1 operation)
 *      Operation 2: b becomes |a - a| = 0. (1 operation)
 *      So, if a == b (and not 0), it takes 1 operation.
 * - If {a, b} is {1, 2}:
 *      Op 1: a becomes |1 - 2| = 1. State becomes (1, 2).
 *      Op 2: b becomes |1 - 2| = 1. State becomes (1, 1).
 *      From (1, 1), we know it takes 1 more operation to reach 0.
 *      So, from (1, 2), it takes 2 operations.
 */

void solve() {
    long long A, B;
    cin >> A >> B;
    
    int a = A % 3;
    int b = B % 3;
    
    if (a == 0 || b == 0) {
        cout << 0 << "\n";
    } else if (a == b) {
        cout << 1 << "\n";
    } else {
        // Case where {a, b} is {1, 2}
        cout << 2 << "\n";
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