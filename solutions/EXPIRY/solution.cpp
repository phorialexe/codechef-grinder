#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Eikooc has N loaves of bread.
 * They expire in M days.
 * She can eat K loaves per day.
 * Total capacity to eat bread before expiration is M * K.
 * If N <= M * K, she can eat all the bread.
 * Otherwise, she cannot.
 * 
 * Constraints: N, M, K <= 100.
 * M * K can be up to 10,000, which fits in a standard integer.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;

        // Calculate total capacity
        // Using long long to prevent any potential overflow, 
        // though int is sufficient for these constraints.
        if (n <= m * k) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}