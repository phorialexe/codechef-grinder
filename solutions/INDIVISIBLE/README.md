# [Indivisible (INDIVISIBLE)](https://www.codechef.com/problems/INDIVISIBLE)

- **Difficulty Rating**: 787
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $A, B,$ and $C$ ($2 \le A, B, C \le 100$), we need to find an integer $K$ ($2 \le K < 100$) such that $K$ does not divide $A$, $K$ does not divide $B$, and $K$ does not divide $C$. In other words, $A \pmod K \neq 0$, $B \pmod K \neq 0$, and $C \pmod K \neq 0$.

## Intuition & Mathematical Observation
The constraints on $A, B,$ and $C$ are very small (up to 100). We are looking for a value $K$ in the range $[2, 99]$. 

Since we only need to find *any* valid $K$, we can use a brute-force approach. By iterating through all possible values of $K$ from 99 down to 2, we can check the divisibility condition for each. Because the range of $K$ is small and the constraints on $A, B, C$ are limited, a valid $K$ is guaranteed to exist within this range.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the range of $K$ (which is constant, 98). Thus, the complexity is effectively $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given A, B, C (2 <= A, B, C <= 100).
 * We need to find a positive integer K < 100 such that:
 * A % K != 0 AND B % K != 0 AND C % K != 0.
 * 
 * Since A, B, C are at most 100, and we need K < 100,
 * we can simply iterate through all integers K from 2 to 99.
 */

void solve() {
    int A, B, C;
    cin >> A >> B >> C;

    // Iterate through possible values of K from 99 down to 2.
    // Given the constraints, a valid K will always exist.
    for (int k = 99; k >= 2; --k) {
        if (A % k != 0 && B % k != 0 && C % k != 0) {
            cout << k << "\n";
            return;
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```