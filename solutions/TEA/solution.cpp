#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs X liters of tea.
 * Each refill provides Y liters and costs Z rupees.
 * If X is divisible by Y, he needs exactly (X / Y) refills.
 * If X is not divisible by Y, he needs (X / Y) + 1 refills to cover the remaining amount.
 * This can be calculated using integer division: ceil(X / Y) = (X + Y - 1) / Y.
 * Total cost = (number of refills) * Z.
 * 
 * Constraints: X, Y, Z <= 100. The result will fit in a standard integer, 
 * but using long long is safe practice.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // Calculate number of refills needed
        // Using integer arithmetic: (x + y - 1) / y performs ceiling division
        long long refills = (x + y - 1) / y;
        
        // Calculate total cost
        long long total_cost = refills * z;

        cout << total_cost << "\n";
    }

    return 0;
}