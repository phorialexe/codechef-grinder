#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given A (solid) and B (liquid):
 * 1. If A > 0 and B > 0, it's a "Solution".
 * 2. If B == 0, it's a "Solid".
 * 3. If A == 0, it's a "Liquid".
 * 
 * Constraints: 0 <= A, B <= 100, A + B > 0.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        if (a > 0 && b > 0) {
            cout << "Solution" << "\n";
        } else if (b == 0) {
            cout << "Solid" << "\n";
        } else if (a == 0) {
            cout << "Liquid" << "\n";
        }
    }
    
    return 0;
}