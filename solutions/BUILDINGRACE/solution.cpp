#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at floor A with speed X. Time taken = A / X.
 * Chefina is at floor B with speed Y. Time taken = B / Y.
 * We need to compare A/X and B/Y.
 * To avoid floating point precision issues, we can compare A/X and B/Y 
 * by cross-multiplying: A * Y vs B * X.
 * If A * Y < B * X, then A/X < B/Y (Chef is faster).
 * If A * Y > B * X, then A/X > B/Y (Chefina is faster).
 * If A * Y == B * X, then A/X == B/Y (Both reach at the same time).
 * 
 * Constraints: A, B <= 100, X, Y <= 10.
 * A * Y and B * X will be at most 1000, which fits in a standard int.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        // Using cross-multiplication to compare fractions A/X and B/Y
        // Chef's time: a/x
        // Chefina's time: b/y
        // Compare (a * y) and (b * x)
        
        int chef_time_scaled = a * y;
        int chefina_time_scaled = b * x;

        if (chef_time_scaled < chefina_time_scaled) {
            cout << "Chef" << "\n";
        } else if (chefina_time_scaled < chef_time_scaled) {
            cout << "Chefina" << "\n";
        } else {
            cout << "Both" << "\n";
        }
    }

    return 0;
}