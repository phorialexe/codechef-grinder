#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Initial temperature: X degrees
 * - Initial solubility: A g / 100 mL
 * - Solubility increase per degree: B g / 100 mL
 * - Target temperature: 100 degrees
 * - Total water: 1 Liter = 1000 mL
 * 
 * Solubility at 100 degrees = A + (100 - X) * B (g / 100 mL)
 * Since we have 1000 mL of water, the total amount of sugar is:
 * Total Sugar = (Solubility at 100 degrees) * (1000 / 100)
 * Total Sugar = (A + (100 - X) * B) * 10
 * 
 * Constraints:
 * X: 31 to 40
 * A: 101 to 120
 * B: 1 to 5
 * Calculations fit well within standard integer types, but long long is used for safety.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, a, b;
        cin >> x >> a >> b;
        
        // Calculate solubility at 100 degrees per 100 mL
        long long solubility_at_100 = a + (100 - x) * b;
        
        // Calculate total sugar for 1000 mL (1 Liter)
        // 1000 mL / 100 mL = 10 units
        long long total_sugar = solubility_at_100 * 10;
        
        cout << total_sugar << "\n";
    }
    
    return 0;
}