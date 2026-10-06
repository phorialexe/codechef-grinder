#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef attacks with power P, then P becomes floor(P/2).
 * This continues until P becomes 0.
 * The total damage dealt is the sum of the geometric series:
 * P + floor(P/2) + floor(P/4) + ... + floor(P/2^k)
 * 
 * Since P <= 10^5, the number of attacks is logarithmic (log2(10^5) approx 17).
 * We can simply simulate the process for each test case.
 * 
 * Time Complexity: O(T * log(P))
 * Space Complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long h, p;
        cin >> h >> p;
        
        long long total_damage = 0;
        long long current_p = p;
        
        // Simulate the attacks
        while (current_p > 0) {
            total_damage += current_p;
            current_p /= 2;
        }
        
        // Check if total damage is enough to kill Darth
        if (total_damage >= h) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}