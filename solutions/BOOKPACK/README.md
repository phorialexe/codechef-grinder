# [Packing Books (BOOKPACK)](https://www.codechef.com/problems/BOOKPACK)

- **Difficulty Rating**: 775
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $X$ shelves, and each shelf contains $Y$ books. Chef wants to pack these books into boxes, where each box can hold at most $Z$ books. A crucial constraint is that books from different shelves cannot be mixed in the same box. We need to calculate the total number of boxes required to pack all the books.

## Intuition & Mathematical Observation
For a single shelf containing $Y$ books, we need to determine how many boxes of capacity $Z$ are required. 
- If $Y$ is perfectly divisible by $Z$, we need $Y/Z$ boxes.
- If there is a remainder, we need an additional box for the remaining books.

This is equivalent to the ceiling function: $\lceil Y / Z \rceil$. In integer arithmetic, the ceiling of $Y/Z$ can be calculated efficiently using the formula:
$$\text{boxes\_per\_shelf} = \frac{Y + Z - 1}{Z}$$

Since there are $X$ shelves and each shelf requires the same number of boxes (because they all contain $Y$ books), the total number of boxes is simply:
$$\text{Total Boxes} = X \times \left\lceil \frac{Y}{Z} \right\rceil$$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X shelves, each with Y books.
 * Each box can hold at most Z books.
 * Books from different shelves cannot be mixed.
 * 
 * For one shelf containing Y books, the number of boxes required is ceil(Y / Z).
 * In integer arithmetic, ceil(Y / Z) can be calculated as (Y + Z - 1) / Z.
 * Since there are X shelves, the total number of boxes is X * ceil(Y / Z).
 * 
 * Constraints: X, Y, Z <= 1000.
 * The result will be at most 1000 * 1000 = 1,000,000, which fits in a standard 32-bit integer.
 * Using long long is safe practice to prevent overflow in larger variations.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // Calculate boxes per shelf: ceil(y / z)
        // Using integer division: (y + z - 1) / z
        long long boxes_per_shelf = (y + z - 1) / z;
        
        // Total boxes = shelves * boxes_per_shelf
        long long total_boxes = x * boxes_per_shelf;

        cout << total_boxes << "\n";
    }

    return 0;
}
```