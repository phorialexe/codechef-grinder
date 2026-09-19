#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Geyser capacity: X litres
 * - Bucket capacity: Y litres
 * - Water required per person: 2 * Y litres
 * - Number of people = floor(X / (2 * Y))
 * 
 * Constraints:
 * - 1 <= T <= 1000
 * - 1 <= X, Y <= 100
 * 
 * Since X and Y are small, standard integer division will work perfectly.
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Each person needs 2 * y litres
        long long water_per_person = 2 * y;
        
        // Calculate maximum people using integer division
        // If water_per_person > x, the result will be 0, which is correct.
        long long max_people = x / water_per_person;
        
        cout << max_people << "\n";
    }
    
    return 0;
}