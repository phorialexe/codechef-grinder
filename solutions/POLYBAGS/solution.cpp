#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each polybag can hold at most 10 items.
 * To find the minimum number of polybags for N items, we need to calculate ceil(N / 10).
 * Using integer arithmetic, ceil(N / 10) can be calculated as (N + 9) / 10.
 * 
 * Constraints:
 * T <= 1000, N <= 1000.
 * The result will fit in a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        // Calculate minimum polybags using integer division
        // (n + 9) / 10 is equivalent to ceil(n / 10.0)
        int polybags = (n + 9) / 10;
        
        cout << polybags << "\n";
    }
    
    return 0;
}