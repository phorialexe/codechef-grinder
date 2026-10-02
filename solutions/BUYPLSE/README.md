# [Buy Please (BUYPLSE)](https://www.codechef.com/problems/BUYPLSE)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to calculate the total cost of purchasing two types of items. Given the quantities of two items ($a$ and $b$) and their respective unit prices ($x$ and $y$), we need to compute the total expenditure using the formula:
$$\text{Total Cost} = (a \times x) + (b \times y)$$

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation. 
- We are given four integers: $a, b, x, y$.
- The constraints state that $1 \le a, b, x, y \le 10^3$.
- The maximum possible value for the total cost is $(10^3 \times 10^3) + (10^3 \times 10^3) = 2 \times 10^6$.
- Since $2 \times 10^6$ is well within the range of a standard 32-bit integer (which goes up to $\approx 2 \times 10^9$), we can safely use `int` or `long long`. Using `long long` is a safe practice in competitive programming to avoid potential overflow issues if constraints were larger.

## Complexity Analysis
- **Time Complexity**: $O(1)$. The solution performs a constant number of arithmetic operations regardless of the input values.
- **Space Complexity**: $O(1)$. We only use a fixed amount of memory to store the four input variables and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Buy Please
 * The total cost is calculated as (a * x) + (b * y).
 * Given constraints: 1 <= a, b, x, y <= 10^3.
 * The maximum possible value is (10^3 * 10^3) + (10^3 * 10^3) = 2 * 10^6.
 * This fits comfortably within a standard 32-bit signed integer, 
 * but using long long is good practice to prevent overflow in similar problems.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a, b, x, y;
    
    // Read the 4 space-separated integers
    if (cin >> a >> b >> x >> y) {
        // Calculate total cost
        long long total_cost = (a * x) + (b * y);
        
        // Output the result
        cout << total_cost << "\n";
    }

    return 0;
}
```