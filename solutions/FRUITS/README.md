# [Chef and Fruits (FRUITS)](https://www.codechef.com/problems/FRUITS)

- **Difficulty Rating**: 1126
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ apples and $M$ oranges. He can perform at most $K$ operations. In each operation, he can increase the count of either apples or oranges by 1. The goal is to minimize the absolute difference between the number of apples and oranges after performing at most $K$ operations.

## Intuition & Mathematical Observation
To minimize the difference $|N - M|$, we should always add the fruit that is currently in the minority. 

1. Let the current counts be $N$ and $M$. Without loss of generality, assume $N \le M$.
2. The difference we want to bridge is $diff = M - N$.
3. Each operation allows us to increment $N$ by 1, which reduces the difference by 1.
4. **Case 1 ($K \ge diff$):** We have enough operations to make $N$ equal to $M$. Once $N = M$, the difference is $0$. Even if we have leftover operations, we can distribute them equally between $N$ and $M$ to keep the difference at $0$.
5. **Case 2 ($K < diff$):** We do not have enough operations to make them equal. We use all $K$ operations to increase $N$. The new difference will be $(M) - (N + K)$, which simplifies to $diff - K$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N apples and M oranges. We can perform at most K operations.
 * Each operation allows us to increase the count of the fruit that is smaller
 * by 1, effectively reducing the absolute difference |N - M|.
 * 
 * Strategy:
 * 1. Identify the smaller quantity and the larger quantity.
 * 2. The difference is diff = |N - M|.
 * 3. We can use up to K coins to close this gap.
 * 4. If K >= diff, we can make the counts equal (difference becomes 0).
 * 5. If K < diff, we can reduce the difference by K (difference becomes diff - K).
 */

void solve() {
    long long n, m, k;
    if (!(cin >> n >> m >> k)) return;

    // Ensure n is the smaller value for simplicity
    if (n > m) {
        swap(n, m);
    }

    // Now n <= m. The difference is m - n.
    // We can increase n by at most k.
    long long diff = m - n;

    if (k >= diff) {
        // We can make them equal, the minimum difference possible is 0.
        cout << 0 << "\n";
    } else {
        // We use all k coins to reduce the difference.
        cout << (diff - k) << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```