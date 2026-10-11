#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X and Y. We need to find all multiples of X in the range [X, Y].
 * Let these multiples be X*1, X*2, X*3, ..., X*k, where X*k <= Y.
 * So k = floor(Y / X).
 * 
 * S_even = sum of (X * i) for all i in {1, ..., k} such that (X * i) is even.
 * S_odd  = sum of (X * i) for all i in {1, ..., k} such that (X * i) is odd.
 * 
 * Since X, Y <= 100, we can simply iterate through all multiples of X up to Y
 * and calculate the sums directly.
 */

void solve() {
    int X, Y;
    cin >> X >> Y;

    long long s_even = 0;
    long long s_odd = 0;

    // Iterate through all multiples of X: X, 2X, 3X, ... up to Y
    for (int i = X; i <= Y; i += X) {
        if (i % 2 == 0) {
            s_even += i;
        } else {
            s_odd += i;
        }
    }

    if (s_even >= s_odd) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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