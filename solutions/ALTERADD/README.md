# [Alternate Additions (ALTERADD)](https://www.codechef.com/problems/ALTERADD)

- **Difficulty Rating**: 863
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, we want to transform $A$ into $B$ by repeatedly applying an alternating sequence of additions: add $1$, then add $2$, then add $1$, then add $2$, and so on. We need to determine if it is possible to reach exactly $B$ starting from $A$ using any number of these operations.

## Intuition & Mathematical Observation
The sequence of operations is $+1, +2, +1, +2, \dots$. 
Notice that every pair of operations adds a total of $1 + 2 = 3$ to the current value.

Let $D = B - A$ be the total difference we need to cover.
- If we perform an even number of operations, we have performed $k$ pairs of $(+1, +2)$, resulting in a total addition of $3k$.
- If we perform an odd number of operations, we have performed $k$ pairs plus one additional $+1$ operation, resulting in a total addition of $3k + 1$.

Therefore, the difference $D$ must be representable in the form $3k$ or $3k + 1$. 
- If $D \pmod 3 = 0$, it is possible (we use only pairs of operations).
- If $D \pmod 3 = 1$, it is possible (we use pairs of operations plus one final $+1$).
- If $D \pmod 3 = 2$, it is **impossible** to reach $B$ because no combination of $3k$ and $3k+1$ can result in a remainder of $2$ when divided by $3$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a subtraction and a modulo operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the difference.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operations are:
 * 1st: +1
 * 2nd: +2
 * 3rd: +1
 * 4th: +2
 * ...
 * Every pair of operations (1st and 2nd, 3rd and 4th, etc.) adds a total of 1 + 2 = 3 to A.
 * Let D = B - A.
 * We want to know if D can be represented as a sum of 1s and 2s following the alternating pattern.
 * 
 * If we perform k pairs of operations, we add 3*k.
 * After these pairs, we might perform one additional operation (+1).
 * So, D can be written as:
 * 1) D = 3k (if we stop after an even number of operations)
 * 2) D = 3k + 1 (if we stop after an odd number of operations)
 * 
 * This means D % 3 must be either 0 or 1.
 * If D % 3 == 2, it is impossible to reach B from A.
 */

void solve() {
    long long A, B;
    cin >> A >> B;
    long long diff = B - A;
    
    // Check if the difference can be represented as 3k or 3k + 1
    if (diff % 3 == 2) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
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