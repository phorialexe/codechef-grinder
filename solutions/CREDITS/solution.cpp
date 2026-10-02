#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Complete the credits
 * Logic:
 * - If X > 65, output "Overload"
 * - If X < 35, output "Underload"
 * - Otherwise, output "Normal"
 * 
 * Time Complexity: O(T), where T is the number of test cases.
 * Space Complexity: O(1), as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x;
        cin >> x;
        
        if (x > 65) {
            cout << "Overload" << "\n";
        } else if (x < 35) {
            cout << "Underload" << "\n";
        } else {
            cout << "Normal" << "\n";
        }
    }
    
    return 0;
}