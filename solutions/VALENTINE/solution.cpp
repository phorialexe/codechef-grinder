#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X rupees and each chocolate costs Y rupees.
 * The maximum number of chocolates Chef can buy is the integer part of X / Y.
 * This is equivalent to floor division in integer arithmetic.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= X, Y <= 100
 * Since X and Y are small, standard integer types are sufficient.
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // The maximum number of chocolates is the quotient of X divided by Y.
        // If X < Y, the result is 0, which is handled correctly by integer division.
        long long max_chocolates = x / y;
        
        cout << max_chocolates << "\n";
    }
    
    return 0;
}