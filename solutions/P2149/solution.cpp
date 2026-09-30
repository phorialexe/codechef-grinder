#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a red rectangle (A x B) and a blue square (X x X).
 * We want Area(Rectangle) <= Area(Square), i.e., A * B <= X * X.
 * Each change of a dimension (A or B) costs 1.
 * Since we want to minimize cost, we check:
 * 0 changes: If A * B <= X * X, cost is 0.
 * 1 change: If we can change A to A' or B to B' such that A' * B <= X * X or A * B' <= X * X.
 *           To minimize the area, we change the dimension to 1.
 *           So, if 1 * B <= X * X or A * 1 <= X * X, cost is 1.
 * 2 changes: If neither of the above works, we change both dimensions to 1.
 *            1 * 1 <= X * X is always true since X >= 1. Cost is 2.
 */

void solve() {
    int A, B, X;
    cin >> A >> B >> X;

    long long area_rect = (long long)A * B;
    long long area_sq = (long long)X * X;

    // Case 0: Already satisfied
    if (area_rect <= area_sq) {
        cout << 0 << "\n";
    } 
    // Case 1: Can we satisfy by changing one dimension to 1?
    // Changing A to 1 makes area 1 * B. Changing B to 1 makes area A * 1.
    else if ((1 * B <= area_sq) || (A * 1 <= area_sq)) {
        cout << 1 << "\n";
    } 
    // Case 2: Change both dimensions to 1
    else {
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