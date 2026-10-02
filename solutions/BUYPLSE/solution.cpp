#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Buy Please
 * The total cost is calculated as (a * x) + (b * y).
 * Given constraints: 1 <= a, b, x, y <= 10^3.
 * The maximum possible value is (10^3 * 10^3) + (10^3 * 10^3) = 2 * 10^6.
 * This fits comfortably within a standard 32-bit signed integer, 
 * but using long long is good practice to prevent overflow in similar problems.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, x, y;
    
    // Read the 4 space-separated integers
    if (cin >> a >> b >> x >> y) {
        // Calculate total cost
        long long total_cost = (a * x) + (b * y);
        
        // Output the result
        cout << total_cost << "\n";
    }

    return 0;
}