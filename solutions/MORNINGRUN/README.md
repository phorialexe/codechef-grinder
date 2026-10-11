# [Morning Run (MORNINGRUN)](https://www.codechef.com/problems/MORNINGRUN)

- **Difficulty Rating**: 306
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to run at least 1000 meters in a rectangular park. Given the length $X$ and width $Y$ of the park, determine if one full lap around the park is sufficient to meet or exceed this goal. A full lap around a rectangle is equivalent to its perimeter.

## Intuition & Mathematical Observation
The perimeter $P$ of a rectangle with length $X$ and width $Y$ is calculated using the formula:
$$P = 2 \times (X + Y)$$

The problem requires us to check if the total distance covered in one lap is at least 1000 meters. Therefore, we simply need to evaluate the condition:
$$2 \times (X + Y) \ge 1000$$

If the condition holds true, output `YES`; otherwise, output `NO`. Given the constraints $1 \le X, Y \le 1000$, the maximum perimeter is 4000, which easily fits within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and comparisons regardless of the input size.
- **Space Complexity**: $O(1)$ — No additional data structures are used; only a few variables are stored in memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The perimeter of a rectangular park with length X and width Y is given by:
 * Perimeter = 2 * (X + Y)
 * Chef needs to run at least 1000 meters.
 * Therefore, we need to check if 2 * (X + Y) >= 1000.
 * 
 * Constraints:
 * 1 <= X, Y <= 1000
 * The maximum perimeter is 2 * (1000 + 1000) = 4000, which fits in a standard 32-bit integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y;
    // Read the length and width of the park
    if (cin >> X >> Y) {
        long long perimeter = 2 * (X + Y);
        
        // Check if the perimeter meets the 1000m requirement
        if (perimeter >= 1000) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```