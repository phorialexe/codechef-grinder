#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Chef needs X pages total. He has Y pages.
 * Pages needed = max(0, X - Y).
 * He has K budget.
 * He needs to find if there exists a notebook (Pi, Ci) such that:
 * 1. Pi >= pages_needed
 * 2. Ci <= K
 * 
 * Complexity: O(N) per test case. Total O(Sum of N), which is 10^6.
 * This fits well within the 1-second time limit.
 */

void solve() {
    int X, Y, K, N;
    if (!(cin >> X >> Y >> K >> N)) return;

    int pages_needed = (X > Y) ? (X - Y) : 0;
    bool found = false;

    for (int i = 0; i < N; ++i) {
        int P, C;
        cin >> P >> C;
        // We must read all N lines regardless of whether we found a match
        // to ensure the input stream is correctly positioned for the next test case.
        if (!found && P >= pages_needed && C <= K) {
            found = true;
        }
    }

    if (found) {
        cout << "LuckyChef" << "\n";
    } else {
        cout << "UnluckyChef" << "\n";
    }
}

int main() {
    // Fast I/O is crucial for 10^6 inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}