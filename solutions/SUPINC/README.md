# [Superincreasing (SUPINC)](https://www.codechef.com/problems/SUPINC)

- **Difficulty Rating**: 1201
- **Solved in**: 3 attempt(s)

## Problem Summary
The problem asks whether it is possible to construct a **superincreasing sequence** of length $K$ such that the $K$-th element is exactly $X$. A sequence $A$ is defined as superincreasing if for every index $i > 1$, the element $A[i]$ is strictly greater than the sum of all preceding elements: $A[i] > \sum_{j=1}^{i-1} A[j]$.

## Intuition & Mathematical Observation
To determine the smallest possible value for the $K$-th element of a superincreasing sequence, we consider the most "compact" sequence possible:
1. Let $A[1] = 1$.
2. To satisfy the condition $A[i] > \sum_{j=1}^{i-1} A[j]$ while keeping values as small as possible, we set $A[i] = \sum_{j=1}^{i-1} A[j] + 1$.

Following this logic:
- $A[1] = 1$
- $A[2] = 1 + 1 = 2$
- $A[3] = (1 + 2) + 1 = 4$
- $A[4] = (1 + 2 + 4) + 1 = 8$
- By induction, the smallest possible value for the $K$-th element is $2^{K-1}$.

**Constraints Analysis:**
The problem states $X \le 10^9$. Since $2^{29} \approx 5.36 \times 10^8$ and $2^{30} \approx 1.07 \times 10^9$, any $K$ such that $K-1 \ge 30$ will result in a minimum value for $A[K]$ that exceeds the maximum possible value of $X$. Therefore, if $K > 30$, it is impossible to satisfy the condition, and we can immediately output "No". Otherwise, we simply check if $X \ge 2^{K-1}$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing simple bitwise shifts and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated minimum value.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * A superincreasing array A satisfies A[i] > sum(A[1]...A[i-1]).
 * The smallest possible value for A[K] is 2^(K-1).
 * 
 * If K-1 >= 30, 2^(K-1) > 10^9. Since X <= 10^9, it is impossible for 
 * any superincreasing array to have A[K] = X if K > 30.
 */

void solve() {
    long long N, K, X;
    if (!(cin >> N >> K >> X)) return;

    // If K is large, 2^(K-1) will exceed the maximum value of X (10^9).
    // 2^29 = 536,870,912
    // 2^30 = 1,073,741,824 (which is > 10^9)
    // If K-1 >= 30, then 2^(K-1) > 10^9, so X cannot be >= 2^(K-1).
    if (K - 1 >= 30) {
        cout << "No" << "\n";
        return;
    }

    // Smallest possible value for A[K] is 2^(K-1)
    long long min_val = (1LL << (K - 1));

    if (X >= min_val) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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