# [Trade Surplus (SURPLUS)](https://www.codechef.com/problems/SURPLUS)

- **Difficulty Rating**: 695
- **Solved in**: 1 attempt(s)

## Problem Summary
In a closed economic system consisting of three countries (A, B, and C), the total trade balance must sum to zero. Given the exports and imports for countries A and B, we need to determine if country C is in a trade surplus. A country is in a trade surplus if its net export (exports minus imports) is strictly greater than zero.

## Intuition & Mathematical Observation
The net export of a country is defined as `Exports - Imports`. Let $net_A$, $net_B$, and $net_C$ be the net exports of countries A, B, and C respectively.

1. We are given:
   - $net_A = A_1 - A_2$
   - $net_B = B_1 - B_2$
2. Since the system is closed, the sum of all net exports must be zero:
   - $net_A + net_B + net_C = 0$
3. Rearranging to solve for $net_C$:
   - $net_C = -(net_A + net_B)$
4. Country C is in a surplus if $net_C > 0$. By substituting the values, we check if $-( (A_1 - A_2) + (B_1 - B_2) ) > 0$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and calculate the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The total trade balance of a closed system of three countries (A, B, and C) must sum to zero.
 * Net Export of A = A1 - A2
 * Net Export of B = B1 - B2
 * Net Export of C = -(Net Export of A + Net Export of B)
 * 
 * A country is in trade surplus if its net export is strictly greater than 0.
 * Therefore, C is in trade surplus if:
 * -( (A1 - A2) + (B1 - B2) ) > 0
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;

        // Calculate net exports for A and B
        long long netA = a1 - a2;
        long long netB = b1 - b2;
        
        // Since the sum of net exports in a closed system is 0:
        // netA + netB + netC = 0
        // netC = -(netA + netB)
        long long netC = -(netA + netB);

        // Check if C has a trade surplus
        if (netC > 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```