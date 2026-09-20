#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two numbers A and B. We need a third number X such that:
 * A + B + X = 21
 * Therefore, X = 21 - (A + B)
 * 
 * Constraints:
 * 1 <= A, B <= 10
 * 1 <= X <= 10
 * 
 * If the calculated X is within the range [1, 10], we output X.
 * Otherwise, it is impossible to win, so we output -1.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int x = 21 - (a + b);
        
        // Check if the required third number is valid (between 1 and 10)
        if (x >= 1 && x <= 10) {
            cout << x << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}