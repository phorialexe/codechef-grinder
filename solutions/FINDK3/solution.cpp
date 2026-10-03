#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three distinct positive integers X, Y, Z.
 * We need to choose one as B, and the product of the other two as A.
 * Condition: A % B == 0.
 * 
 * Possible scenarios:
 * 1. B = X, A = Y * Z. Check if (Y * Z) % X == 0.
 * 2. B = Y, A = X * Z. Check if (X * Z) % Y == 0.
 * 3. B = Z, A = X * Y. Check if (X * Y) % Z == 0.
 * 
 * If any of these satisfy the condition, print A and B.
 * If none satisfy, print -1.
 */

void solve() {
    long long x, y, z;
    if (!(cin >> x >> y >> z)) return;

    // Case 1: B = X, A = Y * Z
    if ((y * z) % x == 0) {
        cout << (y * z) << " " << x << "\n";
        return;
    }
    
    // Case 2: B = Y, A = X * Z
    if ((x * z) % y == 0) {
        cout << (x * z) << " " << y << "\n";
        return;
    }
    
    // Case 3: B = Z, A = X * Y
    if ((x * y) % z == 0) {
        cout << (x * y) << " " << z << "\n";
        return;
    }

    // No solution found
    cout << -1 << "\n";
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