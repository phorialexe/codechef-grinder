# [Fill The Grid (GRIDBL)](https://www.codechef.com/problems/GRIDBL)

- **Difficulty Rating**: 968
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an $N \times M$ grid and an unlimited supply of $2 \times 2$ tiles and $1 \times 1$ tiles. The goal is to cover the entire grid while minimizing the number of $1 \times 1$ tiles used. We need to output the minimum number of $1 \times 1$ tiles required.

## Intuition & Mathematical Observation
To minimize the number of $1 \times 1$ tiles, we must maximize the usage of $2 \times 2$ tiles. A $2 \times 2$ tile covers an area of 4 units.

1. **If both $N$ and $M$ are even**: The grid can be perfectly partitioned into $2 \times 2$ blocks. No $1 \times 1$ tiles are needed. Result: **0**.
2. **If $N$ is odd and $M$ is even**: We can cover the $N-1$ rows using $2 \times 2$ tiles. This leaves one full row of $M$ cells. Since $M$ is even, we can fill this row with $1 \times 2$ blocks (which are just two $1 \times 1$ tiles side-by-side). Thus, we need **$M$** tiles of $1 \times 1$.
3. **If $N$ is even and $M$ is odd**: Similarly, we can cover $M-1$ columns with $2 \times 2$ tiles, leaving one full column of $N$ cells. We need **$N$** tiles of $1 \times 1$.
4. **If both $N$ and $M$ are odd**: We have one row of $M$ cells and one column of $N$ cells remaining. They intersect at a single corner cell. The number of $1 \times 1$ tiles needed is $(N-1) + (M-1) + 1$, which simplifies to **$N + M - 1$**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the dimensions and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To minimize 1x1 tiles, we maximize 2x2 tiles.
 * - If N, M are even: 0 tiles needed.
 * - If N is odd, M is even: M tiles needed.
 * - If N is even, M is odd: N tiles needed.
 * - If both are odd: (N + M - 1) tiles needed.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        if (n % 2 == 0 && m % 2 == 0) {
            cout << 0 << "\n";
        } else if (n % 2 != 0 && m % 2 != 0) {
            cout << (n + m - 1) << "\n";
        } else if (n % 2 != 0) {
            cout << m << "\n";
        } else {
            cout << n << "\n";
        }
    }

    return 0;
}
```