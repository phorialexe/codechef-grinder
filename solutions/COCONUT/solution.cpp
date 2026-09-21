#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given:
 * x_a: water per type A coconut
 * x_b: pulp per type B coconut
 * X_a: total water required
 * X_b: total pulp required
 * 
 * Number of type A coconuts needed = X_a / x_a
 * Number of type B coconuts needed = X_b / x_b
 * Total coconuts = (X_a / x_a) + (X_b / x_b)
 * 
 * Constraints:
 * T <= 15000
 * All values are within standard integer range (100 to 1500), 
 * so int is sufficient, but long long is used for safety.
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long xa, xb, Xa, Xb;
        cin >> xa >> xb >> Xa >> Xb;
        
        // Calculate number of coconuts for each type
        long long countA = Xa / xa;
        long long countB = Xb / xb;
        
        // Output the total
        cout << (countA + countB) << "\n";
    }
    
    return 0;
}