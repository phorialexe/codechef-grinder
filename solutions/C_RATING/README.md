# [Chess Ratings (C_RATING)](https://www.codechef.com/problems/C_RATING)

- **Difficulty Rating**: 651
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice currently has a chess rating of $X$. She wants to achieve a target rating of at least $Y$. In each game she wins, her rating increases by exactly 8 points. The goal is to determine the minimum number of games Alice needs to win to reach a rating of at least $Y$.

## Intuition & Mathematical Observation
To find the number of games $n$ required, we set up the following inequality:
$$X + 8n \ge Y$$

Rearranging to solve for $n$:
$$8n \ge Y - X$$
$$n \ge \frac{Y - X}{8}$$

Since $n$ must be a non-negative integer, we need to find the smallest integer greater than or equal to $\frac{Y - X}{8}$, which is equivalent to the ceiling function:
$$n = \lceil \frac{Y - X}{8} \rceil$$

**Implementation Note:**
In integer arithmetic, the ceiling of $\frac{a}{b}$ can be calculated efficiently using the formula `(a + b - 1) / b`. If $X \ge Y$, Alice has already reached her goal, so the answer is 0.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice starts with rating X and wants to reach rating Y.
 * Each win increases rating by 8.
 * Let n be the number of games won.
 * We need X + 8 * n >= Y
 * 8 * n >= Y - X
 * n >= (Y - X) / 8
 * Since n must be an integer, n = ceil((Y - X) / 8).
 * 
 * Using integer arithmetic, ceil(a / b) can be calculated as (a + b - 1) / b.
 * Here, a = Y - X and b = 8.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        if (x >= y) {
            cout << 0 << "\n";
        } else {
            long long diff = y - x;
            // Calculate ceil(diff / 8) using integer division
            long long n = (diff + 7) / 8;
            cout << n << "\n";
        }
    }

    return 0;
}
```