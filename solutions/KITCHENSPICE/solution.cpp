#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The spice level X is categorized as:
 * - MILD: X < 4
 * - MEDIUM: 4 <= X < 7
 * - HOT: X >= 7
 * 
 * Constraints: 1 <= T <= 1000, 1 <= X <= 10.
 * Time Complexity: O(T) - We perform constant time checks for each test case.
 * Space Complexity: O(1) - No extra space required.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        if (x < 4) {
            cout << "MILD" << "\n";
        } else if (x < 7) {
            cout << "MEDIUM" << "\n";
        } else {
            cout << "HOT" << "\n";
        }
    }
    
    return 0;
}