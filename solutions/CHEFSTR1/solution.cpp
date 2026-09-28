#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To move from string S_i to S_{i+1}, the number of strings skipped is:
 * abs(S_{i+1} - S_i) - 1.
 * 
 * We need to sum this value for all i from 1 to N-1.
 * Constraints:
 * T <= 10
 * N <= 10^5
 * S_i <= 10^6
 * 
 * The total sum can exceed the range of a 32-bit integer (10^5 * 10^6 = 10^11),
 * so we must use 'long long' for the accumulator.
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
        
        vector<long long> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        
        long long total_skipped = 0;
        for (int i = 0; i < n - 1; ++i) {
            // The number of strings between S_i and S_{i+1} is |S_{i+1} - S_i| - 1
            long long diff = abs(s[i+1] - s[i]);
            if (diff > 0) {
                total_skipped += (diff - 1);
            }
        }
        
        cout << total_skipped << "\n";
    }
    
    return 0;
}