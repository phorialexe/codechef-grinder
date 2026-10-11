#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - A cut passes through the center of the circular pizza.
 * - 0 cuts result in 1 piece.
 * - 1 cut results in 2 pieces.
 * - 2 cuts result in 4 pieces.
 * - 3 cuts result in 6 pieces.
 * - In general, k cuts passing through the center result in 2*k pieces.
 * - Exception: 0 cuts result in 1 piece.
 * 
 * So, the possible number of pieces N are:
 * - If N = 1 (0 cuts)
 * - If N is even (N = 2*k, where k >= 1)
 * 
 * Therefore, the condition is: N == 1 OR N % 2 == 0.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        // Check if N is 1 or an even number
        if (n == 1 || n % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}