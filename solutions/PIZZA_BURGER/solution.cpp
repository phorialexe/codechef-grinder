#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Ashish has X rupees.
 * Pizza costs Y, Burger costs Z.
 * Preference: PIZZA > BURGER > NOTHING.
 * 
 * Logic:
 * 1. Check if X >= Y (Can afford Pizza). Since Pizza is preferred, if he can afford it, he eats it.
 * 2. Else, check if X >= Z (Can afford Burger). If he can't afford Pizza but can afford Burger, he eats Burger.
 * 3. Else, he eats NOTHING.
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
        long long x, y, z;
        cin >> x >> y >> z;
        
        if (x >= y) {
            cout << "PIZZA" << "\n";
        } else if (x >= z) {
            cout << "BURGER" << "\n";
        } else {
            cout << "NOTHING" << "\n";
        }
    }
    
    return 0;
}