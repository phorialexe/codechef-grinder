# [Summer Heat (COCONUT)](https://www.codechef.com/problems/COCONUT)

- **Difficulty Rating**: 852
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef needs to fulfill a specific requirement for coconut water and coconut pulp. We are given the amount of water and pulp provided by a single coconut of type A and type B, respectively. We are also given the total amount of water and pulp required. The goal is to calculate the total number of coconuts (type A + type B) needed to meet these requirements.

## Intuition & Mathematical Observation
The problem asks for the total count of coconuts. Since each type A coconut provides a fixed amount of water ($x_a$) and each type B coconut provides a fixed amount of pulp ($x_b$), we can determine the number of coconuts required for each category using simple division:

1.  **Type A Coconuts**: The number of type A coconuts needed is the total water required ($X_a$) divided by the water per coconut ($x_a$).
    $$\text{Count}_A = \frac{X_a}{x_a}$$
2.  **Type B Coconuts**: The number of type B coconuts needed is the total pulp required ($X_b$) divided by the pulp per coconut ($x_b$).
    $$\text{Count}_B = \frac{X_b}{x_b}$$

The total number of coconuts is simply the sum of these two values. Since the problem guarantees that the total requirements are perfectly divisible by the amount provided per coconut, we can use integer division.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given:
 * x_a: water per type A coconut
 * x_b: pulp per type B coconut
 * X_a: total water required
 * X_b: total pulp required
 * 
 * Number of type A coconuts needed = X_a / x_a
 * Number of type B coconuts needed = X_b / x_b
 * Total coconuts = (X_a / x_a) + (X_b / x_b)
 * 
 * Constraints:
 * T <= 15000
 * All values are within standard integer range (100 to 1500), 
 * so int is sufficient, but long long is used for safety.
 * Time complexity per test case: O(1)
 * Total time complexity: O(T)
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long xa, xb, Xa, Xb;
        cin >> xa >> xb >> Xa >> Xb;
        
        // Calculate number of coconuts for each type
        long long countA = Xa / xa;
        long long countB = Xb / xb;
        
        // Output the total
        cout << (countA + countB) << "\n";
    }
    
    return 0;
}
```