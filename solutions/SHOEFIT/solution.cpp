#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given three shoes, each represented as 0 (left) or 1 (right).
 * We need to determine if we can form a pair (one left and one right).
 * 
 * Logic:
 * - If all three shoes are 0, we have no right shoe (0).
 * - If all three shoes are 1, we have no left shoe (0).
 * - In any other case, we have at least one 0 and at least one 1.
 * 
 * Therefore, the condition to be able to go out is:
 * (sum of A, B, C > 0) AND (sum of A, B, C < 3).
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
        
        int sum = a + b + c;
        
        // If sum is 0, all are left shoes.
        // If sum is 3, all are right shoes.
        // Otherwise, we have a mix of 0s and 1s.
        if (sum > 0 && sum < 3) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}