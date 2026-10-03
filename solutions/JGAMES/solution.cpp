#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The game starts with X and lasts for Y moves.
 * In each move, the player can change X by +1 or -1.
 * This means the parity of X changes in every move.
 * After Y moves, the final parity of the number will be:
 * (X + Y) % 2.
 * 
 * If (X + Y) is even, the final number is even, and Janmansh wins.
 * If (X + Y) is odd, the final number is odd, and Jay wins.
 * 
 * Since the players are playing optimally, they don't actually have a choice 
 * that changes the parity outcome. No matter what move a player makes (+1 or -1),
 * the parity of the number flips. Therefore, the final parity is solely 
 * determined by the starting parity and the total number of moves Y.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // The final parity is (x + y) % 2
        // If (x + y) is even, Janmansh wins.
        // If (x + y) is odd, Jay wins.
        if ((x + y) % 2 == 0) {
            cout << "Janmansh" << "\n";
        } else {
            cout << "Jay" << "\n";
        }
    }

    return 0;
}