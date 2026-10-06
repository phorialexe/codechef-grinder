#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef buys X stocks at price Y each. Total cost = X * Y.
 * Chef sells X stocks at price Z each. Total revenue = X * Z.
 * Profit = Total Revenue - Total Cost
 * Profit = (X * Z) - (X * Y)
 * Profit = X * (Z - Y)
 * 
 * Constraints:
 * T <= 100
 * X, Y, Z <= 10^4
 * The maximum possible profit is 10^4 * (10^4 - 1) which is approx 10^8.
 * This fits comfortably within a standard 32-bit signed integer, 
 * but using long long is good practice to prevent overflow in similar problems.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Calculate profit using the derived formula: X * (Z - Y)
        long long profit = x * (z - y);
        
        cout << profit << "\n";
    }
    
    return 0;
}