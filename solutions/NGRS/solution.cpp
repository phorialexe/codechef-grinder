#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grading logic is defined as:
 * 1. If attendance (X) < 50: Grade is 'Z'.
 * 2. Else if marks (Y) < 50: Grade is 'F'.
 * 3. Otherwise: Grade is 'A'.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        if (x < 50) {
            cout << "Z" << "\n";
        } else if (y < 50) {
            cout << "F" << "\n";
        } else {
            cout << "A" << "\n";
        }
    }
    
    return 0;
}