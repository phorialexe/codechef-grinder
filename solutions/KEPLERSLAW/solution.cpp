#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Kepler's Law
 * Kepler's 3rd Law states: T^2 / R^3 = constant
 * We need to check if (T1^2 / R1^3) == (T2^2 / R2^3)
 * To avoid floating point precision issues, we cross-multiply:
 * T1^2 * R2^3 == T2^2 * R1^3
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long t1, t2, r1, r2;
        cin >> t1 >> t2 >> r1 >> r2;

        // Calculate T1^2 * R2^3 and T2^2 * R1^3
        // Given constraints are small (up to 10), so long long is more than sufficient
        long long lhs = (t1 * t1) * (r2 * r2 * r2);
        long long rhs = (t2 * t2) * (r1 * r1 * r1);

        if (lhs == rhs) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}