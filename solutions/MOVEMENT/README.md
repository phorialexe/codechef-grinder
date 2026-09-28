# [Move Grid (MOVEMENT)](https://www.codechef.com/problems/MOVEMENT)

- **Difficulty Rating**: 215
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to track the final coordinates of an object starting at the origin $(0, 0)$ after a sequence of four movements:
1. Move $A$ units in the positive X direction.
2. Move $B$ units in the positive Y direction.
3. Move $C$ units in the negative X direction.
4. Move $D$ units in the negative Y direction.

We need to output the final $(x, y)$ coordinates after these four steps.

## Intuition & Mathematical Observation
The movement can be broken down into simple arithmetic operations on the coordinate plane:
- Starting position: $(0, 0)$
- After step 1 (positive X): $(0 + A, 0) = (A, 0)$
- After step 2 (positive Y): $(A, 0 + B) = (A, B)$
- After step 3 (negative X): $(A - C, B)$
- After step 4 (negative Y): $(A - C, B - D)$

Thus, the final position is simply $(A - C, B - D)$. Since the constraints are small and the operations are basic subtractions, we can compute the result directly.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of arithmetic operations regardless of the input values.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Starting at (0, 0):
 * 1. Move A units along positive X: (A, 0)
 * 2. Move B units along positive Y: (A, B)
 * 3. Move C units along negative X: (A - C, B)
 * 4. Move D units along negative Y: (A - C, B - D)
 * 
 * The final position is (A - C, B - D).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C, D;
    if (!(cin >> A >> B >> C >> D)) return 0;

    int final_x = A - C;
    int final_y = B - D;

    cout << final_x << " " << final_y << endl;

    return 0;
}
```