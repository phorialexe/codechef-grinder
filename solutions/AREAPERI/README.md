# [Area OR Perimeter (AREAPERI)](https://www.codechef.com/problems/AREAPERI)

- **Difficulty Rating**: 858
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the length ($L$) and breadth ($B$) of a rectangle, we need to calculate its area and perimeter. We must compare these two values and output:
1. `"Area"` and the area value if the area is greater than the perimeter.
2. `"Peri"` and the perimeter value if the perimeter is greater than the area.
3. `"Eq"` and the value if both are equal.

## Intuition & Mathematical Observation
The formulas for a rectangle are straightforward:
*   **Area** = $L \times B$
*   **Perimeter** = $2 \times (L + B)$

Since the constraints for $L$ and $B$ are up to $1000$, the maximum area is $1,000,000$ and the maximum perimeter is $4,000$. Both values fit comfortably within a standard 32-bit integer, though `long long` is used here for good practice to prevent overflow in more complex variations. The logic simply requires calculating both values and using a standard `if-else` ladder to compare them.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and comparisons regardless of the input size.
- **Space Complexity**: $O(1)$ — We only store a few variables, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Area OR Perimeter
 * Logic:
 * Area = L * B
 * Perimeter = 2 * (L + B)
 * Compare the two values and output accordingly.
 * Constraints: 1 <= L, B <= 1000. 
 * Max Area = 1,000,000. Max Perimeter = 4,000.
 * Standard 'int' is sufficient, but 'long long' is used for safety.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, B;
    if (!(cin >> L >> B)) return 0;

    long long area = L * B;
    long long peri = 2 * (L + B);

    if (area > peri) {
        cout << "Area" << "\n";
        cout << area << "\n";
    } else if (peri > area) {
        cout << "Peri" << "\n";
        cout << peri << "\n";
    } else {
        // If equal, print "Eq" and the value
        cout << "Eq" << "\n";
        cout << area << "\n";
    }

    return 0;
}
```