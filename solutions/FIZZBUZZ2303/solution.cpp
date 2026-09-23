#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need to select 1 captain and 1 vice-captain from N players.
 * The number of ways to choose the captain is N.
 * The number of ways to choose the vice-captain from the remaining players is (N-1).
 * Total ways = N * (N - 1).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    // Calculate permutations of 2 items from N: P(N, 2) = N * (N - 1)
    int result = N * (N - 1);
    
    cout << result << endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }

    return 0;
}