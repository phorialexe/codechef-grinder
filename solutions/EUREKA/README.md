# [N Queens Puzzle Solved ! (EUREKA)](https://www.codechef.com/problems/EUREKA)

- **Difficulty Rating**: 1109
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to compute the value of $f(N) = (0.143 \times N)^N$ for a given integer $N$ (where $4 \le N \le 15$). The result must be rounded to the nearest integer. Specifically, if the fractional part is less than $0.5$, we round down; otherwise, we round up.

## Intuition & Mathematical Observation
The problem provides a specific formula to calculate the number of ways to place $N$ queens on an $N \times N$ chessboard. Given the small constraints on $N$ ($4 \le N \le 15$), we do not need to implement complex backtracking or dynamic programming. 

We can directly compute the value using the `pow()` function from the `<cmath>` library. Since the input $N$ is small, the resulting value will comfortably fit within a `double` precision floating-point variable. To handle the rounding requirement:
1. The C++ `round()` function returns the nearest integer.
2. For positive numbers, `round(x)` behaves exactly as requested: it rounds to the nearest integer, with halfway cases rounded away from zero (e.g., $0.5$ becomes $1$).

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, the calculation involves a constant time power operation, making the per-test-case complexity $O(1)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: N Queens Puzzle Solved!
 * The task is to calculate f(N) = (0.143 * N)^N and round it to the nearest integer.
 * Given constraints: 4 <= N <= 15.
 * Since N is small, we can use the pow() function from <cmath> which works with doubles.
 * The result will fit within a standard double precision floating point type,
 * and rounding can be performed using the round() function.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        // Calculate (0.143 * N)^N
        double base = 0.143 * (double)n;
        double result = pow(base, (double)n);

        // round() in C++ rounds to the nearest integer, 
        // with halfway cases rounded away from zero.
        // The problem specifies:
        // - Print floor(x) if x - floor(x) < 0.5
        // - Otherwise, print floor(x) + 1
        // This is exactly what round() does for positive numbers.
        long long rounded_result = (long long)round(result);

        cout << rounded_result << "\n";
    }

    return 0;
}
```