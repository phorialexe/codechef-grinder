#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X shelves, each with Y books.
 * Each box can hold at most Z books.
 * Books from different shelves cannot be mixed.
 * 
 * For one shelf containing Y books, the number of boxes required is ceil(Y / Z).
 * In integer arithmetic, ceil(Y / Z) can be calculated as (Y + Z - 1) / Z.
 * Since there are X shelves, the total number of boxes is X * ceil(Y / Z).
 * 
 * Constraints: X, Y, Z <= 1000.
 * The result will be at most 1000 * 1000 = 1,000,000, which fits in a standard 32-bit integer.
 * Using long long is safe practice to prevent overflow in larger variations.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // Calculate boxes per shelf: ceil(y / z)
        // Using integer division: (y + z - 1) / z
        long long boxes_per_shelf = (y + z - 1) / z;
        
        // Total boxes = shelves * boxes_per_shelf
        long long total_boxes = x * boxes_per_shelf;

        cout << total_boxes << "\n";
    }

    return 0;
}