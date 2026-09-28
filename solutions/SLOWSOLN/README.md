# [Slow Solution (SLOWSOLN)](https://www.codechef.com/problems/SLOWSOLN)

- **Difficulty Rating**: 1003
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given three integers: `maxT` (the maximum number of test cases allowed), `maxN` (the maximum value any single test case can take), and `sumN` (the total sum of all test case values). We need to maximize the sum of the squares of the values assigned to each test case, such that the sum of these values does not exceed `sumN` and the number of test cases does not exceed `maxT`.

## Intuition & Mathematical Observation
The function $f(x) = x^2$ is a **convex function**. In optimization, to maximize the sum of squares of a set of numbers with a fixed sum, we should make the individual numbers as large as possible.

1. **Greedy Approach**: To maximize the sum of squares, we should prioritize assigning the largest possible value (`maxN`) to each test case.
2. **Constraints**:
   - We can have at most `maxT` test cases.
   - Each test case can have a value at most `maxN`.
   - The total sum of values is `sumN`.
3. **Logic**:
   - Calculate how many times we can fit `maxN` into `sumN` using `full_blocks = sumN / maxN`.
   - If `full_blocks` is greater than or equal to `maxT`, we simply use `maxT` test cases, each with value `maxN`.
   - If `full_blocks` is less than `maxT`, we use `full_blocks` test cases with value `maxN`, and if there is a remainder (`sumN % maxN`), we use one additional test case with that remainder value.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses basic arithmetic operations. The total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize the sum of squares N_i^2 subject to:
 * 1. 1 <= T <= maxT
 * 2. 1 <= N_i <= maxN
 * 3. Sum of N_i <= sumN
 * 
 * Strategy:
 * - We can have at most 'maxT' values.
 * - We want each value to be as close to 'maxN' as possible.
 * - Let 'count = sumN / maxN'.
 * - If count >= maxT, we can have 'maxT' test cases, each with value 'maxN'.
 * - If count < maxT, we can have 'count' test cases with value 'maxN', 
 *   and one additional test case with value 'sumN % maxN' (if the remainder > 0).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long maxT, maxN, sumN;
        cin >> maxT >> maxN >> sumN;

        long long full_blocks = sumN / maxN;
        long long remainder = sumN % maxN;

        long long ans = 0;
        if (full_blocks >= maxT) {
            // We can fill all maxT slots with maxN
            ans = maxT * (maxN * maxN);
        } else {
            // We use 'full_blocks' slots with maxN, and one slot with 'remainder'
            ans = full_blocks * (maxN * maxN);
            if (remainder > 0) {
                ans += (remainder * remainder);
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
```