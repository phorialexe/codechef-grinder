# [Fit Squares in Triangle (TRISQ)](https://www.codechef.com/problems/TRISQ)

- **Difficulty Rating**: 985
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a right-angled isosceles triangle with a base of length $B$, we need to determine the maximum number of squares of size $2 \times 2$ that can be fitted inside the triangle. The squares must be aligned with the legs of the triangle.

## Intuition & Mathematical Observation
To solve this, let's observe the pattern as the base $B$ increases:
1. A square of size $2 \times 2$ requires a height of 2 units.
2. If $B < 4$, no $2 \times 2$ square can fit.
3. Let $n = B / 2$. This represents the number of $2 \times 2$ blocks that could theoretically fit along the base.
4. As we move up the triangle, each subsequent row has one fewer square than the row below it due to the slope of the hypotenuse.
   - For $B=4$ ($n=2$): 1 square fits.
   - For $B=6$ ($n=3$): $1 + 2 = 3$ squares fit.
   - For $B=8$ ($n=4$): $1 + 2 + 3 = 6$ squares fit.
   - For $B=10$ ($n=5$): $1 + 2 + 3 + 4 = 10$ squares fit.

The pattern follows the sum of the first $(n-1)$ natural numbers. The formula is:
$$\text{Total Squares} = \frac{(n-1) \times n}{2}, \text{ where } n = \lfloor B/2 \rfloor$$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ constant time using the derived formula.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * For a right-angled isosceles triangle of base B, we can fit squares of size 2x2.
 * The number of squares that can fit in each row follows a pattern:
 * If B=4, rows = 1. If B=6, rows = 1+2=3. If B=8, rows = 1+2+3=6.
 * Let n = B / 2. The number of squares is the sum of integers from 1 to (n-1).
 * Formula: (n * (n - 1)) / 2, where n = B / 2.
 */

void solve() {
    int B;
    cin >> B;
    
    // Calculate n = B / 2
    int n = B / 2;
    
    // The number of squares is the sum of (n-1) + (n-2) + ... + 1
    // which is (n-1) * n / 2
    int result = (n * (n - 1)) / 2;
    
    cout << result << endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }

    return 0;
}
```