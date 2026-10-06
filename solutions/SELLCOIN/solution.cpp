#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has A silver coins and B gold coins.
 * - 1 gold coin = 2 silver coins.
 * - 1 silver coin = 1 Rupee.
 * 
 * Total silver coins after trading all gold coins = A + (B * 2).
 * Since each silver coin sells for 1 Rupee, the total money earned is A + 2 * B.
 * 
 * Input Format Correction:
 * The problem statement specifies the input contains only A and B, 
 * without a test case count 't'.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    // Read A and B directly as per the problem description
    if (cin >> A >> B) {
        // Total money = (Initial silver) + (Silver from gold)
        // Each gold coin gives 2 silver coins, and each silver coin is worth 1 Rupee.
        long long total_money = A + (2 * B);
        
        cout << total_money << endl;
    }
    
    return 0;
}