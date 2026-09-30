#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: LUCKYNUM
 * Logic: Check if any of the three input integers A, B, or C is equal to 7.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few integer variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        // Check if any of the digits is 7
        if (a == 7 || b == 7 || c == 7) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}