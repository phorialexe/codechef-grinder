#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Investor 1 offers A for 10% of the company.
 * Valuation 1 = A / 0.10 = A * 10.
 * 
 * Investor 2 offers B for 20% of the company.
 * Valuation 2 = B / 0.20 = B * 5.
 * 
 * We need to compare (A * 10) and (B * 5).
 * If (A * 10) > (B * 5), output FIRST.
 * If (B * 5) > (A * 10), output SECOND.
 * If (A * 10) == (B * 5), output ANY.
 * 
 * Constraints:
 * 100 <= A, B <= 10000.
 * A * 10 max = 100,000.
 * B * 5 max = 50,000.
 * These values fit comfortably within a standard 32-bit integer, 
 * but we use long long for safety as per best practices.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b;
        cin >> a >> b;

        long long val1 = a * 10;
        long long val2 = b * 5;

        if (val1 > val2) {
            cout << "FIRST" << "\n";
        } else if (val2 > val1) {
            cout << "SECOND" << "\n";
        } else {
            cout << "ANY" << "\n";
        }
    }

    return 0;
}