#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to reach exactly N kg using 1kg weights (cost 20) and 2kg weights (cost 30).
 * Let x be the number of 1kg weights and y be the number of 2kg weights.
 * We want to minimize Cost = 20x + 30y subject to x + 2y = N.
 * 
 * From x + 2y = N, we get x = N - 2y.
 * Since x >= 0, we must have 2y <= N, so y <= N/2.
 * Substituting x:
 * Cost = 20(N - 2y) + 30y
 * Cost = 20N - 40y + 30y
 * Cost = 20N - 10y
 * 
 * To minimize the cost, we need to maximize y.
 * The maximum possible value for y is floor(N / 2).
 * 
 * Therefore, the minimum cost is 20N - 10 * floor(N / 2).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Maximize y = n / 2
        long long y = n / 2;
        long long cost = 20 * n - 10 * y;
        
        cout << cost << "\n";
    }
    
    return 0;
}