#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Candidates join in groups of 5.
 * Original day for candidate i: ceil(i / 5.0)
 * 
 * If candidate K leaves, all candidates with index > K shift down by 1.
 * A candidate i (where i > K) originally joined on day ceil(i / 5.0).
 * After K leaves, the new index of candidate i is i - 1.
 * The new joining day for candidate i is ceil((i - 1) / 5.0).
 * 
 * We need to count how many i > K satisfy:
 * ceil(i / 5.0) != ceil((i - 1) / 5.0)
 * 
 * ceil(x / 5.0) changes value only when x is a multiple of 5 + 1.
 * Specifically, ceil(i / 5.0) != ceil((i - 1) / 5.0) if and only if i is 
 * of the form 5m + 1.
 * 
 * So we need to count how many integers i in the range [K+1, N] 
 * satisfy (i - 1) % 5 == 0.
 */

void solve() {
    int N, K;
    cin >> N >> K;

    // The original day for candidate i is (i + 4) / 5 using integer division.
    // The new day for candidate i (where i > K) is (i - 1 + 4) / 5 = (i + 3) / 5.
    
    int changed_count = 0;
    for (int i = K + 1; i <= N; ++i) {
        int original_day = (i + 4) / 5;
        int new_day = (i + 3) / 5;
        
        if (original_day != new_day) {
            changed_count++;
        }
    }
    
    cout << changed_count << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}