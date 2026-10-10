#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The chessboard cell (i, j) is white if (i + j) is even, and black if (i + j) is odd.
 * The new piece can move from (A, B) to (P, Q) in 1 move if the color of (A, B) 
 * is different from the color of (P, Q).
 * 
 * Let color(i, j) = (i + j) % 2.
 * 1. If (A, B) == (P, Q), the piece is already there. Moves = 0.
 * 2. If color(A, B) != color(P, Q), the piece can reach the destination in 1 move.
 * 3. If color(A, B) == color(P, Q) and (A, B) != (P, Q), the piece cannot reach 
 *    the destination in 1 move. However, it can move to any cell of the opposite 
 *    color in 1 move, and from that cell, it can reach the destination in 1 move.
 *    Total moves = 2.
 */

void solve() {
    int A, B, P, Q;
    cin >> A >> B >> P >> Q;

    // Case 0: Already at the destination
    if (A == P && B == Q) {
        cout << 0 << "\n";
        return;
    }

    // Determine colors
    int color1 = (A + B) % 2;
    int color2 = (P + Q) % 2;

    // Case 1: Different colors, can reach in 1 move
    if (color1 != color2) {
        cout << 1 << "\n";
    } 
    // Case 2: Same color, need 2 moves (move to opposite color, then to destination)
    else {
        cout << 2 << "\n";
    }
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