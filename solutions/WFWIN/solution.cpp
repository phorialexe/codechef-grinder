#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let W be the number of wrong submissions.
 * Each wrong submission adds 20 to the penalty and consumes 1 minute (plus 1 minute wait).
 * However, the problem states: "The team must then wait at least one minute before making the next submission."
 * If the first wrong submission is at minute M, the next can be at M+2, M+4, etc.
 * Wait, let's re-read: "The team must then wait at least one minute before making the next submission."
 * This means if a wrong submission is at time T, the next can be at T+2.
 * 
 * Let W be the number of wrong submissions.
 * The wrong submissions occur at M, M+2, M+4, ..., M + 2*(W-1).
 * The penalty from wrong submissions is W * 20.
 * After W wrong submissions, the earliest time to submit correctly is M + 2*W.
 * Total penalty = P + (W * 20) + (M + 2*W) = P + M + 22*W.
 * We need P + M + 22*W <= 1000.
 * Also, the correct submission must be at time X < 300.
 * So, M + 2*W < 300.
 * 
 * We want to maximize W such that:
 * 1) 22*W <= 1000 - P - M
 * 2) 2*W < 300 - M
 * 
 * Let's check the sample cases:
 * 1) M=294, P=40:
 *    22*W <= 1000 - 40 - 294 = 666 => W <= 30.27
 *    2*W < 300 - 294 = 6 => W < 3 => W <= 2.
 *    Wait, the sample explanation says 5 wrong submissions.
 *    "Chef can make wrong submissions at minutes 294, 295, 296, 297, 298, and then a correct submission at minute 299."
 *    Ah, the wait is "at least one minute". So if he submits at 294, he can submit at 295.
 *    So the wrong submissions can be at M, M+1, M+2, ..., M+W-1.
 *    Penalty = P + 20*W + (M+W) = P + M + 21*W.
 *    Constraint: P + M + 21*W <= 1000.
 *    Constraint: M + W < 300.
 * 
 * Re-checking Sample 1: M=294, P=40.
 * 40 + 294 + 21*W <= 1000 => 334 + 21*W <= 1000 => 21*W <= 666 => W <= 31.7
 * 294 + W < 300 => W < 6 => W <= 5.
 * Max W = 5. Matches sample!
 */

void solve() {
    int M, P;
    cin >> M >> P;
    
    // We need to find max W such that:
    // 1) P + M + 21*W <= 1000
    // 2) M + W < 300
    
    int max_w_penalty = (1000 - P - M) / 21;
    int max_w_time = 299 - M;
    
    int ans = min(max_w_penalty, max_w_time);
    
    // W cannot be negative
    if (ans < 0) ans = 0;
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}