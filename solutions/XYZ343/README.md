# [Savings Account (XYZ343)](https://www.codechef.com/problems/XYZ343)

- **Difficulty Rating**: 720
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $X$ income sources, each yielding $Y$ rupees. The total income is $X \times Y$. However, the bank has a limit $Z$ on the total income Chef can have. If the total income exceeds $Z$, Chef must reduce the number of income sources. We need to find the minimum number of sources Chef must remove so that the remaining income is less than or equal to $Z$.

## Intuition & Mathematical Observation
1. **Calculate Total Income**: First, calculate the current total income as $X \times Y$.
2. **Check Constraint**: If $X \times Y \le Z$, Chef does not need to remove any sources. The answer is $0$.
3. **Calculate Required Reduction**: If $X \times Y > Z$, we need to find the maximum number of sources $N$ such that $N \times Y \le Z$.
   - Rearranging the inequality: $N \le \frac{Z}{Y}$.
   - Since $N$ must be an integer, $N = \lfloor \frac{Z}{Y} \rfloor$.
4. **Determine Sources to Remove**: The number of sources to remove is the original number of sources minus the maximum number of sources allowed: $k = X - N$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X income sources, each providing Y rupees.
 * Total potential income = X * Y.
 * The bank limit is Z.
 * If (X * Y) <= Z, Chef doesn't need to reduce any sources (0).
 * If (X * Y) > Z, Chef needs to reduce the number of sources (let's say k sources)
 * such that the remaining income (X - k) * Y <= Z.
 * 
 * We want to minimize k, which is equivalent to maximizing (X - k).
 * Let N = X - k be the number of sources kept.
 * We need N * Y <= Z, so N <= Z / Y.
 * Since N must be an integer, the maximum N is floor(Z / Y).
 * The number of sources to reduce is k = X - N.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // Total income if no sources are reduced
        long long total_income = x * y;

        if (total_income <= z) {
            cout << 0 << "\n";
        } else {
            // We need to find the maximum number of sources N such that N * Y <= Z
            // N = floor(Z / Y)
            long long n_max = z / y;
            
            // The number of sources to reduce is X - N
            long long reduced = x - n_max;
            
            cout << reduced << "\n";
        }
    }

    return 0;
}
```