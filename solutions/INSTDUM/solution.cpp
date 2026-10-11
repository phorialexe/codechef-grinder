#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Strike Rate = (Total Runs / Total Balls) * 100
 * We want Strike Rate == 100.
 * This is equivalent to: (Total Runs / Total Balls) * 100 = 100
 * Dividing both sides by 100: Total Runs / Total Balls = 1
 * Which simplifies to: Total Runs == Total Balls.
 * 
 * We need to maintain a running sum of runs and compare it to the 
 * current ball count (index + 1) at each step.
 * 
 * Constraints:
 * N <= 10^5, Sum of N <= 10^6.
 * Total runs can be at most 6 * 10^5, which fits in a standard 32-bit integer,
 * but using long long is safer and good practice.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    long long current_runs = 0;
    int count = 0;
    
    for (int i = 1; i <= n; ++i) {
        int runs;
        cin >> runs;
        current_runs += runs;
        
        // After i balls, if total runs == i, strike rate is 100
        if (current_runs == (long long)i) {
            count++;
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}