# [Run for Fun (RURT)](https://www.codechef.com/problems/RURT)

- **Difficulty Rating**: 375
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef needs to run a total distance of $Y$ kilometers. He takes a rest break every $X$ kilometers. Specifically, he rests at the $X, 2X, 3X, \dots$ kilometer marks. However, he does not rest if he has already reached or passed the total distance $Y$. We need to calculate the total number of rest stops Chef makes during his run.

## Intuition & Mathematical Observation
The problem asks for the number of multiples of $X$ that are strictly less than $Y$. 

1. If $Y \le X$, Chef reaches the destination before or exactly at the first rest point, so he makes **0** stops.
2. If $Y > X$, we are looking for the largest integer $k$ such that $k \cdot X < Y$.
3. This inequality $k \cdot X < Y$ is equivalent to $k \cdot X \le Y - 1$.
4. Dividing both sides by $X$, we get $k \le \frac{Y - 1}{X}$. Since $k$ must be an integer, the number of stops is simply the result of integer division: `(Y - 1) / X`.

This formula works universally for all cases where $Y > X$. If $Y \le X$, the formula `(Y - 1) / X` also yields 0, making the logic consistent.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a single arithmetic calculation regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef runs X km before resting. Total distance is Y km.
 * He stops at X, 2X, 3X, ... km marks.
 * He only stops if the distance is strictly less than Y.
 * 
 * If Y <= X, he finishes before or exactly at the first rest point, so 0 stops.
 * If Y > X, he stops at X, 2X, ..., kX where kX < Y.
 * The number of such stops is the largest integer k such that kX < Y.
 * This is equivalent to kX <= Y - 1, or k <= (Y - 1) / X.
 * Since k must be an integer, k = (Y - 1) / X.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    if (!(cin >> X >> Y)) return 0;

    // If Y <= X, the result of (Y - 1) / X is 0, which is correct.
    // Example: X=3, Y=3 -> (3-1)/3 = 0.
    // Example: X=4, Y=3 -> (3-1)/4 = 0.
    // Example: X=1, Y=2 -> (2-1)/1 = 1.
    // Example: X=2, Y=5 -> (5-1)/2 = 2.
    
    if (Y <= X) {
        cout << 0 << endl;
    } else {
        cout << (Y - 1) / X << endl;
    }

    return 0;
}
```