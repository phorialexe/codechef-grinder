# [Basketball Score (P1BAR)](https://www.codechef.com/problems/P1BAR)

- **Difficulty Rating**: 206
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to calculate the total score of a basketball team given the number of successful 3-point shots ($X$) and 2-point shots ($Y$). The total score is defined as the sum of points from both types of shots.

## Intuition & Mathematical Observation
In basketball, a 3-pointer is worth 3 points and a 2-pointer is worth 2 points. Given $X$ successful 3-point shots and $Y$ successful 2-point shots, the total score can be calculated using the linear equation:
$$\text{Total Score} = (X \times 3) + (Y \times 2)$$
Since the constraints are small ($1 \le X, Y \le 10$), a simple arithmetic calculation is sufficient and highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution performs a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Basketball Score
 * Logic: Total score = (X * 3) + (Y * 2)
 * Constraints: 1 <= X, Y <= 10.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read X (3-pointers) and Y (2-pointers)
    long long X, Y;
    if (cin >> X >> Y) {
        // Calculate total score
        long long total_score = (X * 3) + (Y * 2);
        cout << total_score << "\n";
    }

    return 0;
}
```