#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X runs scored in 100 balls.
 * Let s be the number of sixers (6 runs).
 * Let r be the remaining runs (X - 6*s).
 * Let b be the number of balls used for sixers (s balls).
 * The remaining balls are (100 - s).
 * 
 * We need to check if it's possible to score the remaining runs (r) 
 * using the remaining balls (100 - s), where each ball can be 0, 1, 2, 3, or 4.
 * 
 * Constraints:
 * 1. 0 <= s <= 100
 * 2. r = X - 6*s >= 0
 * 3. The maximum runs possible with (100 - s) balls is 4 * (100 - s).
 *    So, we need r <= 4 * (100 - s).
 * 
 * Substituting r:
 * X - 6*s <= 400 - 4*s
 * X - 400 <= 2*s
 * s >= (X - 400) / 2
 * 
 * Also, since we want to maximize s, we start from the largest possible s 
 * such that 6*s <= X and s <= 100, and check the condition r <= 4*(100-s).
 */

void solve() {
    int X;
    if (!(cin >> X)) return;

    // We want the largest s such that:
    // 1. 6*s <= X
    // 2. s <= 100
    // 3. X - 6*s <= 4 * (100 - s)
    
    // From condition 3:
    // X - 6*s <= 400 - 4*s
    // X - 400 <= 2*s
    // s >= (X - 400) / 2
    
    // Since X <= 200, (X - 400) / 2 is always negative, 
    // so the constraint is effectively just 6*s <= X and s <= 100.
    // We want the maximum s, so we start checking from floor(X/6).
    
    for (int s = X / 6; s >= 0; --s) {
        int remaining_runs = X - 6 * s;
        int remaining_balls = 100 - s;
        
        // Can we score remaining_runs in remaining_balls using 0, 1, 2, 3, 4?
        // Max possible is 4 * remaining_balls.
        // Min possible is 0.
        if (remaining_runs >= 0 && remaining_runs <= 4 * remaining_balls) {
            cout << s << "\n";
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    // The problem description implies a single input X, 
    // but standard competitive programming practice handles t if specified.
    // Given the constraints and format, we handle the single input.
    solve();

    return 0;
}