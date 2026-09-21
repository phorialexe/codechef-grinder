#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Speed Limit Test
 * Speed = Distance / Time
 * Alice's speed = A / X
 * Bob's speed = B / Y
 * To compare A/X and B/Y without floating point precision issues,
 * we compare A * Y and B * X.
 * If A * Y > B * X, then Alice is faster.
 * If A * Y < B * X, then Bob is faster.
 * If A * Y == B * X, then they are equal.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, x, b, y;
        cin >> a >> x >> b >> y;

        // Using cross-multiplication to compare fractions A/X and B/Y
        // A/X vs B/Y  =>  A*Y vs B*X
        long long alice_val = a * y;
        long long bob_val = b * x;

        if (alice_val > bob_val) {
            cout << "ALICE" << "\n";
        } else if (bob_val > alice_val) {
            cout << "BOB" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }

    return 0;
}