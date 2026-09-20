#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two problems A and B.
 * A starts at 500 points, loses 2 points per minute.
 * B starts at 1000 points, loses 4 points per minute.
 * 
 * Order 1: A then B
 * Time for A: X
 * Time for B: X + Y
 * Score A: 500 - (X * 2)
 * Score B: 1000 - ((X + Y) * 4)
 * Total 1: 1500 - 2X - 4X - 4Y = 1500 - 6X - 4Y
 * 
 * Order 2: B then A
 * Time for B: Y
 * Time for A: X + Y
 * Score B: 1000 - (Y * 4)
 * Score A: 500 - ((X + Y) * 2)
 * Total 2: 1500 - 4Y - 2X - 2Y = 1500 - 2X - 6Y
 * 
 * We need to calculate both and take the maximum.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Option 1: A then B
        long long score1 = (500 - (x * 2)) + (1000 - ((x + y) * 4));
        
        // Option 2: B then A
        long long score2 = (1000 - (y * 4)) + (500 - ((x + y) * 2));

        // Output the maximum of the two
        cout << max(score1, score2) << "\n";
    }

    return 0;
}