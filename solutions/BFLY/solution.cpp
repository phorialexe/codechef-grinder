#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have R red, G green, and B blue butterflies and flowers.
 * Each butterfly must feed on a flower of a different color.
 * Let the total number of butterflies be N = R + G + B.
 * 
 * A butterfly of color X cannot feed on a flower of color X.
 * This is equivalent to saying that the number of butterflies of color X
 * must be less than or equal to the total number of flowers of other colors.
 * 
 * Specifically:
 * 1. R <= G + B
 * 2. G <= R + B
 * 3. B <= R + G
 * 
 * If these three conditions are met, it is always possible to arrange the 
 * matching. This is a classic result related to Hall's Marriage Theorem or 
 * the construction of Latin squares/bipartite matching in this specific 
 * configuration.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long r, g, b;
        cin >> r >> g >> b;

        // Check the conditions:
        // No color can exceed the sum of the other two colors.
        // If one color is greater than the sum of the others, 
        // there aren't enough "other" flowers to accommodate those butterflies.
        if (r <= g + b && g <= r + b && b <= r + g) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}