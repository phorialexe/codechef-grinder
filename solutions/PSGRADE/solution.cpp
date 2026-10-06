#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef passes if:
 * 1. A >= A_min
 * 2. B >= B_min
 * 3. C >= C_min
 * 4. (A + B + C) >= T_min
 * 
 * Constraints are small (up to 300), so standard integer types are sufficient.
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 */

void solve() {
    int A_min, B_min, C_min, T_min, A, B, C;
    if (!(cin >> A_min >> B_min >> C_min >> T_min >> A >> B >> C)) return;

    // Check individual subject requirements
    bool subject1 = (A >= A_min);
    bool subject2 = (B >= B_min);
    bool subject3 = (C >= C_min);
    
    // Check total score requirement
    bool total = ((A + B + C) >= T_min);

    if (subject1 && subject2 && subject3 && total) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}