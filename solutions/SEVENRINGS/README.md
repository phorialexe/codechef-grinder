# [7 Rings (SEVENRINGS)](https://www.codechef.com/problems/SEVENRINGS)

- **Difficulty Rating**: 568
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine if a phone number is valid based on the total cost of items purchased. A phone number is considered valid if it consists of exactly 5 digits and does not contain a leading zero. Given the number of items $N$ and the cost per item $X$, we calculate the total bill $B = N \times X$ and check if it satisfies these conditions.

## Intuition & Mathematical Observation
1. **Digit Constraint**: A 5-digit number must fall within the range $[10000, 99999]$.
2. **Leading Zero Constraint**: By definition, any number in the range $[10000, 99999]$ cannot have a leading zero (as the first digit must be at least 1). Therefore, we only need to verify if the product $N \times X$ falls within this inclusive range.
3. **Data Types**: The maximum possible value for $N$ and $X$ is $1000$. Thus, the maximum product is $1000 \times 1000 = 1,000,000$. This fits comfortably within a standard 32-bit `int`, though `long long` is used for robustness.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated bill, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A valid phone number consists of exactly 5 digits with no leading zeros.
 * This means the number must be in the range [10000, 99999].
 * 
 * Given N items at cost X, the total bill is B = N * X.
 * We need to check if 10000 <= B <= 99999.
 * 
 * Constraints:
 * 1 <= N, X <= 1000
 * Max B = 1000 * 1000 = 1,000,000.
 * This fits within a standard 32-bit integer, but using long long is safer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        long long total_bill = n * x;
        
        // Check if the bill is exactly 5 digits and has no leading zeros.
        // A number has 5 digits if it is >= 10000 and <= 99999.
        // Since the smallest 5-digit number is 10000, it cannot have a leading zero.
        if (total_bill >= 10000 && total_bill <= 99999) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```