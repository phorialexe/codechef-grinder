#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "hardest" problem is defined as the one with the minimum number of successful submissions.
 * We are given S_A, S_B, S_C.
 * - If min(S_A, S_B, S_C) == S_C, Alice wins.
 * - If min(S_A, S_B, S_C) == S_B, Bob wins.
 * - If min(S_A, S_B, S_C) == S_A, it's a Draw.
 * 
 * Constraints are small (1 to 100), so standard integer types are sufficient.
 */

void solve() {
    int sa, sb, sc;
    if (!(cin >> sa >> sb >> sc)) return;

    // Find the minimum value among the three
    int min_val = min({sa, sb, sc});

    if (min_val == sc) {
        cout << "Alice" << "\n";
    } else if (min_val == sb) {
        cout << "Bob" << "\n";
    } else {
        cout << "Draw" << "\n";
    }
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