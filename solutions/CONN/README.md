# [Construct N (CONN)](https://www.codechef.com/problems/CONN)

- **Difficulty Rating**: 860
- **Solved in**: 1 attempt(s)

## Problem Summary
The objective is to determine if a given integer $N$ can be expressed as the sum of non-negative multiples of 2 and 7. That is, we need to check if there exist non-negative integers $X$ and $Y$ such that:
$$N = 2X + 7Y$$

## Intuition & Mathematical Observation
This is a variation of the **Frobenius Coin Problem**. We are looking for combinations of 2 and 7 that sum up to $N$.

1. **Even Numbers**: Any even number $N \ge 0$ can be represented by setting $Y=0$ and $X = N/2$. Thus, all even numbers are possible.
2. **Odd Numbers**: To represent an odd number, we must use an odd number of 7s (since $2X$ is always even). 
   - If we use one 7 ($Y=1$), the remaining value is $N - 7$. 
   - If $N - 7 \ge 0$ and $N - 7$ is even, then $N$ can be represented as $7(1) + 2(\frac{N-7}{2})$.
   - This covers all odd numbers $N \ge 7$.
3. **Impossible Cases**:
   - $N=1$: Cannot be formed (too small).
   - $N=3$: Cannot be formed ($3-7 < 0$, and 3 is not even).
   - $N=5$: Cannot be formed ($5-7 < 0$, and 5 is not even).

By testing these cases, we observe that all integers $N$ except $\{1, 3, 5\}$ can be represented as $2X + 7Y$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of comparisons. The total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find if N = 2X + 7Y for non-negative integers X, Y.
 * 
 * Logic:
 * - If N is even, we can always represent it as 2*X (Y=0).
 * - If N is odd, we need at least one 7. If (N - 7) >= 0 and (N - 7) is even,
 *   it is representable.
 * - The values 1, 3, and 5 cannot be formed.
 */

void solve() {
    long long N;
    cin >> N;

    // The only impossible values for N >= 0 are 1, 3, and 5.
    if (N == 1 || N == 3 || N == 5) {
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