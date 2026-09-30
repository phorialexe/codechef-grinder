#include <iostream>
#include <vector>

/**
 * Problem Analysis:
 * Chef needs H hours. He has x hours.
 * He can travel to a time zone T_i.
 * He succeeds if x + T_i >= H for any i.
 * 
 * Complexity: O(N) time, O(1) space.
 */

using namespace std;

void solve() {
    int N, H, x;
    if (!(cin >> N >> H >> x)) return;

    bool possible = false;
    for (int i = 0; i < N; ++i) {
        int T;
        cin >> T;
        if (x + T >= H) {
            possible = true;
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Standard competitive programming optimization
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case, but 
    // wrapping in a way that handles standard input correctly.
    solve();

    return 0;
}