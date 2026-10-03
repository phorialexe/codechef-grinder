#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The robot starts at position X.
 * It executes N commands.
 * We need to count the number of distinct integer coordinates visited.
 * Since N is small (up to 100), we can track all visited positions using a set.
 * The set will automatically handle duplicates, and the size of the set
 * will be the number of distinct points visited.
 * 
 * Time Complexity: O(N log N) per test case due to set insertions.
 * Space Complexity: O(N) to store the visited coordinates.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    string S;
    cin >> S;

    set<long long> visited;
    long long current_pos = X;
    
    // The robot starts at X, so X is visited initially.
    visited.insert(current_pos);

    for (char move : S) {
        if (move == 'L') {
            current_pos--;
        } else if (move == 'R') {
            current_pos++;
        }
        visited.insert(current_pos);
    }

    cout << visited.size() << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}