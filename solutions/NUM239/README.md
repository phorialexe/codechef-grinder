# [Counting Pretty Numbers (NUM239)](https://www.codechef.com/problems/NUM239)

- **Difficulty Rating**: 873
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a range $[L, R]$. A number is considered "pretty" if its last digit is 2, 3, or 9. The task is to count the total number of pretty numbers within the inclusive range $[L, R]$.

## Intuition & Mathematical Observation
The problem asks for a count over a range, which can be solved using the prefix sum principle:
$$\text{Result} = f(R) - f(L - 1)$$
where $f(N)$ is the count of pretty numbers in the range $[1, N]$.

**Key Observation:**
Numbers repeat their last digits in cycles of 10 (0-9, 10-19, 20-29, etc.). In every block of 10 consecutive integers, there are exactly three numbers ending in 2, 3, or 9.
1. **Full Blocks:** For any number $N$, there are $\lfloor N/10 \rfloor$ full blocks of 10. Each block contributes 3 to the count.
2. **Remaining Part:** After accounting for full blocks, we are left with $N \pmod{10}$ digits. We simply iterate from 1 to $N \pmod{10}$ and check if the current digit is 2, 3, or 9 to add the remaining pretty numbers.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the loop runs at most 10 times (for the remainder), the operation is constant time. For $T$ test cases, the total complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables for calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A number is "pretty" if its last digit is 2, 3, or 9.
 * We need to count how many such numbers exist in the range [L, R].
 * 
 * Approach:
 * Let f(N) be the count of pretty numbers in the range [1, N].
 * The answer for [L, R] is f(R) - f(L - 1).
 * 
 * In every block of 10 numbers (e.g., 0-9, 10-19, ...), there are exactly 3 pretty numbers:
 * the ones ending in 2, 3, and 9.
 */

long long countPretty(int n) {
    if (n < 0) return 0;
    // Each block of 10 contains 3 pretty numbers
    long long count = (n / 10) * 3;
    
    // Check the remaining digits
    int rem = n % 10;
    for (int i = 1; i <= rem; ++i) {
        if (i == 2 || i == 3 || i == 9) {
            count++;
        }
    }
    return count;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int L, R;
        cin >> L >> R;
        cout << countPretty(R) - countPretty(L - 1) << "\n";
    }
    return 0;
}
```