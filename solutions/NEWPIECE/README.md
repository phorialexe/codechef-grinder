# [New Piece (NEWPIECE)](https://www.codechef.com/problems/NEWPIECE)

- **Difficulty Rating**: 1216
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a chessboard of size $8 \times 8$. A "new piece" is placed at coordinates $(A, B)$ and needs to reach $(P, Q)$. The piece moves such that it always lands on a square of a different color than the one it is currently on. We need to find the minimum number of moves required to reach the destination.

## Intuition & Mathematical Observation
A standard chessboard follows a parity pattern where a cell $(i, j)$ is white if $(i + j)$ is even and black if $(i + j)$ is odd. 

1. **Color Parity**: Let $C(i, j) = (i + j) \pmod 2$.
2. **Move Rule**: The piece moves from a square of color $C_1$ to a square of color $C_2$ if and only if $C_1 \neq C_2$.
3. **Case Analysis**:
    * **0 Moves**: If $(A, B) = (P, Q)$, the piece is already at the destination.
    * **1 Move**: If the starting cell $(A, B)$ and the destination $(P, Q)$ have different colors (i.e., $(A+B) \pmod 2 \neq (P+Q) \pmod 2$), the piece can reach the destination in exactly one move.
    * **2 Moves**: If the starting cell and destination have the same color, the piece cannot reach the destination in one move. However, it can move to any adjacent square of the opposite color in one move, and from there, it can reach the destination in a second move. Thus, the answer is 2.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations and conditional checks. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the coordinates and colors.

## Solution Code

```cpp
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
```