#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let 'ones' be the number of 1s in the string and 'zeros' be the number of 0s.
 * We want to reach a state where the string contains only 0s.
 * 
 * Strategy 1: Delete all 1s.
 * Cost = 'ones'.
 * 
 * Strategy 2: Flip the string, then delete the remaining 1s.
 * If we flip, the 0s become 1s and the 1s become 0s.
 * The number of 1s becomes 'zeros'.
 * Cost = 1 (for flip) + 'zeros' (to delete the new 1s).
 * 
 * We can also combine these:
 * If we flip, we have 'zeros' number of 1s. We can either delete them all, 
 * or delete some and flip again (though flipping twice is redundant).
 * 
 * The minimum operations will be:
 * min(ones, zeros + 1)
 * 
 * Why?
 * - If we don't flip: we must delete all 'ones'. Cost = ones.
 * - If we flip: we perform 1 operation, and now we have 'zeros' number of 1s.
 *   We must delete all these 'zeros' 1s. Cost = 1 + zeros.
 * 
 * Time Complexity: O(N) per test case to count 1s and 0s.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ones = 0;
    int zeros = 0;
    for (char c : s) {
        if (c == '1') {
            ones++;
        } else {
            zeros++;
        }
    }

    // Option 1: Just delete all 1s
    int ans = ones;

    // Option 2: Flip once, then delete all resulting 1s (which were originally 0s)
    // Cost is 1 (flip) + zeros (number of 1s after flip)
    ans = min(ans, zeros + 1);

    cout << ans << "\n";
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