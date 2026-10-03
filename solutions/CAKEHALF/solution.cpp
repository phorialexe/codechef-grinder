#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two integers A and B representing slices of cake.
 * While A != B, Charlie eats half (rounded up) of the larger pile.
 * We need to count the total number of slices eaten.
 * 
 * Since A, B <= 100, a direct simulation is perfectly efficient.
 * The number of operations will be small because the larger value 
 * decreases significantly in each step.
 */

void solve() {
    long long A, B;
    if (!(cin >> A >> B)) return;

    long long total_eaten = 0;

    while (A != B) {
        if (A > B) {
            // Charlie eats half of A, rounded up.
            // (A + 1) / 2 is the integer arithmetic equivalent of ceil(A / 2.0)
            long long eaten = (A + 1) / 2;
            total_eaten += eaten;
            A -= eaten;
        } else {
            // Charlie eats half of B, rounded up.
            long long eaten = (B + 1) / 2;
            total_eaten += eaten;
            B -= eaten;
        }
    }

    cout << total_eaten << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}