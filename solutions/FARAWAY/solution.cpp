#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize the sum of |A_i - B_i| where 1 <= B_i <= M.
 * For each element A_i, the value |A_i - B_i| is maximized when B_i is as far 
 * from A_i as possible within the range [1, M].
 * The two extreme points in the range [1, M] are 1 and M.
 * Therefore, for each A_i, we should choose B_i = 1 or B_i = M.
 * The maximum distance for a single element A_i is max(|A_i - 1|, |A_i - M|).
 * Since |A_i - 1| = A_i - 1 and |A_i - M| = M - A_i,
 * the maximum distance for A_i is max(A_i - 1, M - A_i).
 * 
 * The total maximum distance is the sum of these values for all i from 1 to N.
 * Since M can be up to 10^9 and N up to 2*10^5, the total sum can exceed 2^31-1,
 * so we must use long long for the sum.
 */

void solve() {
    int N;
    long long M;
    if (!(cin >> N >> M)) return;
    
    long long total_distance = 0;
    for (int i = 0; i < N; ++i) {
        long long A_i;
        cin >> A_i;
        
        // Calculate distance if B_i = 1: |A_i - 1| = A_i - 1
        // Calculate distance if B_i = M: |A_i - M| = M - A_i
        long long dist1 = A_i - 1;
        long long dist2 = M - A_i;
        
        total_distance += max(dist1, dist2);
    }
    
    cout << total_distance << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}