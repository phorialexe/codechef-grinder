# [Avoid Contact (AVOIDCONTACT)](https://www.codechef.com/problems/AVOIDCONTACT)

- **Difficulty Rating**: 907
- **Solved in**: 3 attempt(s)

## Problem Summary
We are given $X$ total people, where $Y$ of them are infected. We need to arrange them in a row of rooms such that no two infected people are adjacent. We want to find the minimum number of rooms required to accommodate all $X$ people under this constraint.

## Intuition & Mathematical Observation
To minimize the number of rooms, we must place infected people such that they are separated by at least one empty room or one healthy person.

1. **Case 1: No infected people ($Y = 0$)**
   - If there are no infected people, we can place all $X$ healthy people in adjacent rooms.
   - **Result**: $X$ rooms.

2. **Case 2: All people are infected ($X = Y$)**
   - To keep $Y$ infected people separated, we use the pattern: `I _ I _ I ... I`.
   - We need $Y$ rooms for the infected people and $Y-1$ empty rooms to act as buffers between them.
   - **Result**: $Y + (Y - 1) = 2Y - 1$ rooms.

3. **Case 3: Some people are healthy ($X > Y$)**
   - We have $Y$ infected people and $X-Y$ healthy people.
   - We place the $Y$ infected people in the pattern `I _ I _ I ... I`, which uses $2Y - 1$ rooms.
   - We still have $X-Y$ healthy people to place. Since healthy people do not need to be separated from each other or from infected people (as long as the infected are already separated), we can place the remaining $X-Y$ people in the existing empty buffer rooms or add them to the end.
   - Effectively, each infected person $Y$ requires 2 rooms (themselves + a buffer), except for the last infected person who doesn't need a trailing buffer. However, because we have healthy people, we can use them as buffers.
   - The logic simplifies to: $Y$ infected people need $Y$ rooms, and they need $Y$ buffers to stay separated. If we have healthy people, we use them to fill the gaps. The total count becomes $X + Y$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing simple arithmetic operations. The total time complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * - If Y = 0: All X people are healthy. They can sit in adjacent rooms. N = X.
 * - If Y > 0: 
 *   Each infected person needs to be isolated. 
 *   The pattern C _ C _ C uses 2Y - 1 rooms for Y infected people.
 *   If there are healthy people (X - Y > 0), we need an extra empty room 
 *   to separate the healthy block from the infected block.
 *   Total rooms = (2Y - 1) + 1 (buffer) + (X - Y) = X + Y.
 *   If X == Y, the formula X + Y gives 2Y, but we only need 2Y - 1.
 */

void solve() {
    int X, Y;
    cin >> X >> Y;
    
    if (Y == 0) {
        // No infected people, no special spacing needed
        cout << X << endl;
    } else if (X == Y) {
        // All are infected, need buffers between every pair
        cout << 2 * Y - 1 << endl;
    } else {
        // Mixed group, infected need buffers, healthy fill the gaps
        cout << X + Y << endl;
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```