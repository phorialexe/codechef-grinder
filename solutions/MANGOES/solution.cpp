#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let N be the number of mangoes.
 * The total weight is (N * X) + Y.
 * The bridge can withstand weight Z.
 * We need: (N * X) + Y <= Z
 * N * X <= Z - Y
 * N <= (Z - Y) / X
 * Since we want the maximum number of mangoes, N = floor((Z - Y) / X).
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= X <= Y <= Z <= 100
 * Since the values are small, standard integer types are sufficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        
        // Calculate the remaining capacity for mangoes
        int remaining_capacity = z - y;
        
        // Calculate maximum number of mangoes
        // Since X >= 1, we don't need to worry about division by zero.
        int max_mangoes = remaining_capacity / x;
        
        cout << max_mangoes << "\n";
    }
    
    return 0;
}