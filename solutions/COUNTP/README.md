# [Counting Problem (COUNTP)](https://www.codechef.com/problems/COUNTP)

- **Difficulty Rating**: 1065
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, determine if it is possible to partition the array into two non-empty subsequences $S_1$ and $S_2$ such that the product of their sums, $\text{sum}(S_1) \times \text{sum}(S_2)$, is odd.

## Intuition & Mathematical Observation
For the product of two integers to be odd, both integers must be odd. Therefore, we require:
1. $\text{sum}(S_1)$ must be odd.
2. $\text{sum}(S_2)$ must be odd.

**Key Observations:**
*   **Parity of Sums:** A sum is odd if and only if it contains an odd number of odd integers.
*   **Total Sum:** Let $O$ be the total count of odd numbers in the array. Since $\text{sum}(S_1) + \text{sum}(S_2) = \text{sum}(A)$, and the sum of two odd numbers is even, the total sum of the array must be even. This implies that the total count of odd numbers ($O$) must be even.
*   **Feasibility:** 
    *   If $O = 0$, all numbers are even. Any subsequence sum will be even, so the product will be even.
    *   If $O$ is odd, the total sum is odd. It is impossible to partition an odd sum into two odd numbers (since odd + odd = even).
    *   If $O \ge 2$ and $O$ is even, we can always place one odd number in $S_1$ (making its sum odd) and the remaining $(O-1)$ odd numbers in $S_2$. Since $(O-1)$ is odd, the sum of $S_2$ will also be odd.

**Conclusion:** A valid partition exists if and only if the total count of odd numbers in the array is **even and at least 2**.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to count the odd numbers.
- **Space Complexity**: $O(1)$, as we only store the count of odd numbers and the current input integer.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To make sum(S1) * sum(S2) odd, both sums must be odd.
 * This requires the total number of odd integers in the array to be even 
 * and at least 2.
 */

void solve() {
    int N;
    cin >> N;
    int odd_count = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        if (a % 2 != 0) {
            odd_count++;
        }
    }

    // Condition: Total odd numbers must be even and at least 2
    if (odd_count >= 2 && odd_count % 2 == 0) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```