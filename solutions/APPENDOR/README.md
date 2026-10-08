# [Append for OR (APPENDOR)](https://www.codechef.com/problems/APPENDOR)

- **Difficulty Rating**: 1201
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers and a target integer $Y$, we need to find the smallest non-negative integer $X$ such that the bitwise OR of all elements in the array $A$ combined with $X$ equals $Y$. That is, $(A_1 \mid A_2 \mid \dots \mid A_N \mid X) = Y$. If no such $X$ exists, output $-1$.

## Intuition & Mathematical Observation
Let $S$ be the bitwise OR of all elements in the array $A$ ($S = A_1 \mid A_2 \mid \dots \mid A_N$). The problem reduces to finding the smallest $X$ such that $(S \mid X) = Y$.

1.  **Feasibility Condition**: The bitwise OR operation can only turn bits from $0$ to $1$; it can never turn a $1$ into a $0$. Therefore, if there is any bit set in $S$ that is not set in $Y$, it is impossible to reach $Y$. Mathematically, this condition is checked by verifying if $(S \mid Y) == Y$. If this is false, we output $-1$.
2.  **Finding $X$**: If the condition holds, we need $S \mid X = Y$. To minimize $X$, we should only set the bits in $X$ that are present in $Y$ but missing in $S$. Any bit present in both $S$ and $Y$ does not need to be set in $X$. Thus, the minimal $X$ is given by $X = Y \setminus S$, which in bitwise terms is $X = Y \ \& \ (\sim S)$. Since we already verified that all bits in $S$ are contained in $Y$, this is equivalent to $X = Y \oplus S$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to compute the bitwise OR of all elements.
- **Space Complexity**: $O(1)$, as we only store the running OR sum and the input variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S = A_1 | A_2 | ... | A_N.
 * We need to find the minimum X such that (S | X) = Y.
 * 
 * Properties of Bitwise OR:
 * 1. If any bit is set in S but not in Y, it is impossible to reach Y by ORing X, 
 *    because ORing can only turn bits from 0 to 1, never 1 to 0.
 *    Condition: (S | Y) must be equal to Y.
 * 2. If the condition holds, we need (S | X) = Y.
 *    To minimize X, we should only set the bits in X that are in Y but not in S.
 *    X = Y ^ S.
 */

void solve() {
    int N;
    long long Y;
    cin >> N >> Y;
    
    long long current_or = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        current_or |= a;
    }
    
    // Check if current_or is a subset of Y
    // If (current_or | Y) != Y, it means there is a bit set in current_or 
    // that is not set in Y. Since OR only adds bits, we can't reach Y.
    if ((current_or | Y) != Y) {
        cout << -1 << "\n";
    } else {
        // We need X such that (current_or | X) == Y.
        // To minimize X, we take the bits that are in Y but not in current_or.
        long long X = (Y ^ current_or);
        cout << X << "\n";
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