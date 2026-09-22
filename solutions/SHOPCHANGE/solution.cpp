#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef pays 100 rupees for items worth X rupees.
 * The change to be received is simply 100 - X.
 * Constraints: 1 <= X <= 100.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the change
        int change = 100 - x;
        
        // Output the result
        cout << change << "\n";
    }
    
    return 0;
}