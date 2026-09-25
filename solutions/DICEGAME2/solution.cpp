#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem: DICEGAME2
 * Logic: The sum of the two highest rolls out of three is equivalent to:
 * (Sum of all three) - (Minimum of the three).
 * 
 * Complexity: O(T) time, O(1) space.
 */

void solve() {
    int a1, a2, a3, b1, b2, b3;
    if (!(cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3)) return;

    // Calculate Alice's score: sum of two highest
    int alice_score = (a1 + a2 + a3) - min({a1, a2, a3});

    // Calculate Bob's score: sum of two highest
    int bob_score = (b1 + b2 + b3) - min({b1, b2, b3});

    if (alice_score > bob_score) {
        cout << "Alice" << "\n";
    } else if (bob_score > alice_score) {
        cout << "Bob" << "\n";
    } else {
        cout << "Tie" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}