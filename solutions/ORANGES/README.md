# [Too Many Oranges (ORANGES)](https://www.codechef.com/problems/ORANGES)

- **Difficulty Rating**: 735
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ oranges, and each orange can have exactly 10, 11, or 12 slices. Given a total number of slices $K$, determine if it is possible to have exactly $K$ slices using $N$ oranges.

## Intuition & Mathematical Observation
To solve this, we need to determine the range of possible total slices for $N$ oranges:

1.  **Minimum Slices**: The smallest possible sum occurs when every orange has 10 slices.
    *   $Min = N \times 10$
2.  **Maximum Slices**: The largest possible sum occurs when every orange has 12 slices.
    *   $Max = N \times 12$

**Can we achieve every integer value between $Min$ and $Max$?**
Yes. We can start with all $N$ oranges having 10 slices. By changing one orange at a time from 10 to 11, we increase the total sum by 1 until we reach $N \times 11$. Then, by changing one orange at a time from 11 to 12, we increase the total sum by 1 until we reach $N \times 12$. 

Because we can increment the total sum by 1 at each step without skipping any values, any $K$ such that $(N \times 10) \le K \le (N \times 12)$ is achievable.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculated bounds.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N oranges, each having 10, 11, or 12 slices.
 * The total number of slices K must satisfy:
 * Minimum possible slices = N * 10
 * Maximum possible slices = N * 12
 * 
 * Since we can choose any combination of 10, 11, or 12 slices for each of the N oranges,
 * we can achieve any integer sum K such that:
 * (N * 10) <= K <= (N * 12)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        long long min_slices = n * 10;
        long long max_slices = n * 12;

        // Check if K falls within the reachable range [min_slices, max_slices]
        if (k >= min_slices && k <= max_slices) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```