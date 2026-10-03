# [Janmansh and Games (JGAMES)](https://www.codechef.com/problems/JGAMES)

- **Difficulty Rating**: 772
- **Solved in**: 1 attempt(s)

## Problem Summary
Janmansh and Jay are playing a game starting with an integer $X$. They make $Y$ moves in total. In each move, the current number is replaced by either $X+1$ or $X-1$. Janmansh goes first, and they take turns. The player who makes the last move wins if the final number is even, and the other player wins if it is odd. We need to determine the winner assuming both play optimally.

## Intuition & Mathematical Observation
The key to this problem lies in the property of **parity** (evenness or oddness). 

1. **Parity Flip**: Adding 1 or subtracting 1 from any integer always changes its parity. If $X$ is even, $X \pm 1$ becomes odd. If $X$ is odd, $X \pm 1$ becomes even.
2. **Predictability**: Since every move flips the parity, the parity of the final number after $Y$ moves is entirely determined by the starting number $X$ and the total number of moves $Y$.
3. **The Logic**:
   - After 1 move, the parity is the opposite of $X$.
   - After 2 moves, the parity returns to the original parity of $X$.
   - Generally, after $Y$ moves, the parity of the final number will be the same as $(X + Y) \pmod 2$.
4. **Winning Condition**:
   - If $(X + Y)$ is even, the final number is even, and Janmansh wins.
   - If $(X + Y)$ is odd, the final number is odd, and Jay wins.

Because the parity flip is forced regardless of the choice of $+1$ or $-1$, the "optimal play" mentioned in the problem is a distractor; the outcome is fixed by the initial state and the number of moves.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic check. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform the calculation.

## Solution Code

```cpp
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
```