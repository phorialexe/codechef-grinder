#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Qualify the round
 * Logic:
 * Easy problems are worth 1 point, Hard problems are worth 2 points.
 * Total score = (A * 1) + (B * 2).
 * Chef qualifies if Total score >= X.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, a, b;
        cin >> x >> a >> b;
        
        // Calculate total score
        // Using long long to prevent overflow, though constraints (100) fit in int.
        long long total_score = (a * 1) + (b * 2);
        
        if (total_score >= x) {
            cout << "Qualify" << "\n";
        } else {
            cout << "NotQualify" << "\n";
        }
    }
    
    return 0;
}