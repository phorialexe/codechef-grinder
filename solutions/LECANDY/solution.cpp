#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N elephants and C total candies.
 * Each elephant i requires at least A[i] candies.
 * To make all elephants happy, we need to provide at least A[i] candies to each elephant i.
 * The total number of candies required is the sum of all A[i] for i from 1 to N.
 * If sum(A[i]) <= C, then it is possible to make all elephants happy.
 * Otherwise, it is not.
 * 
 * Constraints:
 * T <= 1000
 * N <= 100
 * C <= 10^9
 * A[i] <= 10000
 * 
 * Since N * max(A[i]) = 100 * 10000 = 1,000,000, which fits in a standard 32-bit integer,
 * but C can be up to 10^9, using long long for the sum is safe and good practice.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        long long c;
        cin >> n >> c;
        
        long long total_needed = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            total_needed += a;
        }
        
        if (total_needed <= c) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}