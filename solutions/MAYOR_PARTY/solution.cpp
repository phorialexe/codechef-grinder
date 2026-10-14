#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three regions A, B, and C with populations P_A, P_B, and P_C.
 * Constraints:
 * 1. If B is invited, A and C cannot be invited.
 * 2. If A or C are invited, B cannot be invited.
 * 
 * Possible scenarios:
 * Scenario 1: Invite people from region B. Total = P_B.
 * Scenario 2: Invite people from regions A and C. Total = P_A + P_C.
 * 
 * We need to find the maximum of these two scenarios.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long pa, pb, pc;
        cin >> pa >> pb >> pc;

        // Option 1: Invite only region B
        long long option1 = pb;
        
        // Option 2: Invite regions A and C
        long long option2 = pa + pc;

        // Output the maximum of the two options
        cout << max(option1, option2) << "\n";
    }

    return 0;
}