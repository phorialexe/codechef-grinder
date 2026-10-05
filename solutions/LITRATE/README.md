# [Literacy Rate (LITRATE)](https://www.codechef.com/problems/LITRATE)

- **Difficulty Rating**: 512
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the population $P$ of a city and the number of literate people $L$, determine if the literacy rate is at least 75%. The literacy rate is calculated as $\frac{L}{P} \times 100$. If the result is greater than or equal to 75, output "YES"; otherwise, output "NO".

## Intuition & Mathematical Observation
The condition provided is:
$$\frac{L}{P} \times 100 \ge 75$$

While we could perform floating-point division, it is safer and more efficient to use integer arithmetic to avoid precision errors. By multiplying both sides by $P$, we get:
$$L \times 100 \ge 75 \times P$$

Given the constraints $1 \le L \le P \le 100$, the maximum value for $L \times 100$ is $10,000$, which easily fits within a standard integer type. This cross-multiplication approach ensures the solution is robust and avoids any potential issues with rounding or floating-point representation.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform the comparison.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Literacy Rate
 * The condition is (L / P) * 100 >= 75.
 * To avoid floating point precision issues, we can rewrite this as:
 * L * 100 >= 75 * P
 * 
 * Given constraints: 1 <= L <= P <= 100.
 * The maximum value of L * 100 is 10,000.
 * This fits comfortably within a standard 32-bit integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long p, l;
        cin >> p >> l;
        
        // Check if (L / P) * 100 >= 75
        // Using cross-multiplication to avoid floating point arithmetic:
        // L * 100 >= 75 * P
        if (l * 100 >= 75 * p) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```