#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total time in minutes = N * K
 * We need to convert this total time into Hours (H) and Minutes (M).
 * H = Total_Minutes / 60
 * M = Total_Minutes % 60
 * 
 * Constraints:
 * N <= 30, K < 60
 * Max total minutes = 30 * 59 = 1770
 * This fits comfortably within a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, k;
        if (!(cin >> n >> k)) break;
        
        long long total_minutes = n * k;
        
        long long h = total_minutes / 60;
        long long m = total_minutes % 60;
        
        cout << h << " " << m << "\n";
    }
    
    return 0;
}