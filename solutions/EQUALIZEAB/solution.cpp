#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with A and B. In one operation, we change (A, B) to (A+X, B-X) or (A-X, B+X).
 * Let the number of times we add X to A be 'k' (where k can be positive, negative, or zero).
 * After k operations, the new values are:
 * A' = A + k*X
 * B' = B - k*X
 * We want A' = B', so:
 * A + k*X = B - k*X
 * 2 * k * X = B - A
 * k = (B - A) / (2 * X)
 * 
 * For A and B to be equal, (B - A) must be divisible by (2 * X).
 * Since k must be an integer, (B - A) % (2 * X) must be 0.
 * 
 * Note: The problem states we can apply the operation any number of times.
 * If A == B initially, the answer is YES (k=0).
 * Otherwise, the difference (B - A) must be a multiple of 2X.
 */

void solve() {
    long long A, B, X;
    cin >> A >> B >> X;

    // The difference between A and B changes by 2*X in each operation.
    // Let diff = B - A.
    // Each operation changes the difference by 2*X or -2*X.
    // We need the initial difference to be reachable by adding/subtracting 2*X.
    // This is equivalent to saying (B - A) must be divisible by (2 * X).
    
    long long diff = B - A;
    if (diff % (2 * X) == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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