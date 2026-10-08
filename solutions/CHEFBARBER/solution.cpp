#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N customers ahead of him.
 * Each customer takes M minutes.
 * The total time Chef has to wait is the sum of the time taken for all N customers.
 * Total Wait Time = N * M.
 * 
 * Constraints:
 * N <= 1000, M <= 1000.
 * The maximum possible value is 1000 * 1000 = 1,000,000.
 * This fits comfortably within a standard 32-bit integer, but using long long 
 * is a safe practice in competitive programming to prevent overflow in similar problems.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // The wait time is simply the number of people ahead multiplied by time per person.
        // If N = 0, the result is 0 * M = 0, which is correct.
        long long wait_time = n * m;
        
        cout << wait_time << "\n";
    }
    
    return 0;
}