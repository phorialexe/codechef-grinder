# [Expiring Bread (EXPIRY)](https://www.codechef.com/problems/EXPIRY)

- **Difficulty Rating**: 440
- **Solved in**: 1 attempt(s)

## Problem Summary
Eikooc has $N$ loaves of bread. The bread expires in $M$ days, and she can consume at most $K$ loaves per day. We need to determine if it is possible for Eikooc to finish all $N$ loaves before or on the day they expire.

## Intuition & Mathematical Observation
The problem asks whether the total number of loaves $N$ can be consumed within the given timeframe. 
- Eikooc has $M$ days to eat the bread.
- Each day, she can eat $K$ loaves.
- Therefore, the maximum number of loaves she can consume before the bread expires is $M \times K$.

If $N \le M \times K$, she can finish all the bread, so the answer is **"Yes"**. Otherwise, if $N > M \times K$, she will have leftover bread that expires, so the answer is **"No"**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a simple multiplication and comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Eikooc has N loaves of bread.
 * They expire in M days.
 * She can eat K loaves per day.
 * Total capacity to eat bread before expiration is M * K.
 * If N <= M * K, she can eat all the bread.
 * Otherwise, she cannot.
 * 
 * Constraints: N, M, K <= 100.
 * M * K can be up to 10,000, which fits in a standard integer.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;

        // Calculate total capacity
        // Using long long to prevent any potential overflow, 
        // though int is sufficient for these constraints.
        if (n <= m * k) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```