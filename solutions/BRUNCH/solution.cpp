#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X plates and each neighbour takes Y plates.
 * We need to find the maximum number of neighbours that can be fed completely.
 * This is equivalent to finding the floor of (X / Y).
 * However, there is a constraint: there are only 20 neighbours.
 * Therefore, the answer is min(20, X / Y).
 * 
 * Constraints:
 * 1 <= T <= 405
 * 20 <= X <= 100
 * 1 <= Y <= 5
 * 
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate how many neighbours can be fed with X plates
        long long fed = x / y;
        
        // Chef only has 20 neighbours, so the maximum he can feed is 20
        long long result = min(20LL, fed);
        
        cout << result << "\n";
    }
    
    return 0;
}