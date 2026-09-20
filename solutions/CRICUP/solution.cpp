#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Cup Finals
 * The problem asks us to determine if the absolute difference between two 
 * skill levels X and Y is less than or equal to D.
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
        long long x, y, d;
        cin >> x >> y >> d;
        
        // Calculate the absolute difference between skill levels
        long long diff = abs(x - y);
        
        // Check if the difference is within the allowed threshold D
        if (diff <= d) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}