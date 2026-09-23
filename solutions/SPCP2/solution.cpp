#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each plane carries 100 passengers.
 * Total passengers = N.
 * Total planes required = ceil(N / 100.0).
 * Using integer arithmetic, ceil(N / 100) is equivalent to (N + 99) / 100.
 * Let R be the required planes. R = (N + 99) / 100.
 * If the airline already has X planes, the number of new planes needed is:
 * max(0, R - X).
 * 
 * Constraints:
 * X, N <= 10^6.
 * Calculations fit within standard 32-bit integers, but using long long is safer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, n;
        cin >> x >> n;

        // Calculate total planes needed using integer ceiling division
        long long total_planes_needed = (n + 99) / 100;

        // Calculate additional planes to purchase
        long long to_purchase = total_planes_needed - x;

        // If to_purchase is negative, it means we have enough planes, so output 0
        if (to_purchase < 0) {
            cout << 0 << "\n";
        } else {
            cout << to_purchase << "\n";
        }
    }

    return 0;
}