#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has A units of syrup and B units of water.
 * The ratio must be 1:2.
 * Let x be the amount of syrup used. Then 2x must be the amount of water used.
 * Constraints:
 * x <= A
 * 2x <= B
 * Therefore, x <= min(A, B/2).
 * Since x must be an integer, x = min(A, B/2).
 * The total quantity of juice is x + 2x = 3x.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long A, B;
        cin >> A >> B;

        // We need to find the maximum integer x such that:
        // x <= A
        // 2x <= B  => x <= B/2
        
        long long x = min(A, B / 2);
        
        // Total quantity is x (syrup) + 2x (water) = 3x
        long long total_juice = 3 * x;
        
        cout << total_juice << "\n";
    }

    return 0;
}