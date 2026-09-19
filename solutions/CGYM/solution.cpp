#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has a budget Z.
 * Gym cost = X.
 * Trainer cost = Y.
 * 
 * Logic:
 * 1. Check if Chef can afford both: (X + Y) <= Z. If yes, output 2.
 * 2. If not, check if Chef can afford just the gym: X <= Z. If yes, output 1.
 * 3. If neither, output 0.
 * 
 * Constraints:
 * X, Y, Z are between 1 and 100.
 * Standard integer types are sufficient, but long long is used for safety.
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
        
        // Check if both gym and trainer are affordable
        if (x + y <= z) {
            cout << "2" << "\n";
        }
        // Check if only gym is affordable
        else if (x <= z) {
            cout << "1" << "\n";
        }
        // Cannot afford gym
        else {
            cout << "0" << "\n";
        }
    }
    
    return 0;
}