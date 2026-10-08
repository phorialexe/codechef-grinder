#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation described is:
 * 1. If X > Y, swap(X, Y)
 * 2. Else, X = Y - X, Y = X
 * 
 * Let's trace the Euclidean algorithm for GCD(X, Y):
 * GCD(X, Y) = GCD(X, Y - X)
 * 
 * In the given operation:
 * If X > Y: swap(X, Y) -> X becomes the smaller value, Y becomes the larger.
 * If X <= Y: X becomes (Y - X), Y becomes the old X.
 * 
 * This is exactly the Euclidean algorithm for finding the Greatest Common Divisor.
 * The process continues until X becomes 0. When X is 0, the value of Y is the GCD of the original X and Y.
 * 
 * Time Complexity: O(log(min(X, Y))) per test case due to the Euclidean algorithm.
 * Space Complexity: O(1).
 */

void solve() {
    long long X, Y;
    if (!(cin >> X >> Y)) return;
    
    // The problem describes the Euclidean algorithm.
    // The final value of Y when X becomes 0 is gcd(X, Y).
    cout << std::gcd(X, Y) << "\n";
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