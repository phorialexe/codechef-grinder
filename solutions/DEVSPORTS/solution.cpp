#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Devendra starts with Z amount and has already spent Y.
 * The remaining budget is (Z - Y).
 * He wants to try three sports with costs A, B, and C.
 * The total cost for the sports is (A + B + C).
 * He can try all sports if (Z - Y) >= (A + B + C).
 * 
 * Constraints:
 * Z, Y, A, B, C fit within standard integer types, but using long long 
 * is a safe practice in competitive programming to prevent overflow.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long Z, Y, A, B, C;
        cin >> Z >> Y >> A >> B >> C;
        
        // Calculate remaining money after initial expenses
        long long remaining_budget = Z - Y;
        
        // Calculate total cost of the three sports
        long long total_sports_cost = A + B + C;
        
        // Check if he can afford all sports
        if (remaining_budget >= total_sports_cost) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}