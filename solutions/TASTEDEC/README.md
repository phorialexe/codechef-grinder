# [Tasty Decisions (TASTEDEC)](https://www.codechef.com/problems/TASTEDEC)

- **Difficulty Rating**: 324
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to compare the total tastiness of two different snack packets:
1. A chocolate packet containing 2 bars, each with a tastiness value of $X$.
2. A candy packet containing 5 pieces, each with a tastiness value of $Y$.

We need to determine which packet has a higher total tastiness. If the chocolate packet is tastier, output "Chocolate". If the candy packet is tastier, output "Candy". If they are equal, output "Either".

## Intuition & Mathematical Observation
To solve this, we calculate the total tastiness for each packet:
*   **Total Chocolate Tastiness** = $2 \times X$
*   **Total Candy Tastiness** = $5 \times Y$

By comparing these two values using standard conditional statements (`if-else`), we can determine the result:
*   If $2X > 5Y$, the chocolate packet is superior.
*   If $5Y > 2X$, the candy packet is superior.
*   If $2X = 5Y$, both are equal.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the input variables $X$ and $Y$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Tasty Decisions
 * Logic:
 * - Chocolate packet contains 2 bars of tastiness X: Total = 2 * X
 * - Candy packet contains 5 pieces of tastiness Y: Total = 5 * Y
 * - Compare 2*X and 5*Y and output the result.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        long long chocolate_tastiness = 2 * x;
        long long candy_tastiness = 5 * y;
        
        if (chocolate_tastiness > candy_tastiness) {
            cout << "Chocolate" << "\n";
        } else if (candy_tastiness > chocolate_tastiness) {
            cout << "Candy" << "\n";
        } else {
            cout << "Either" << "\n";
        }
    }
    
    return 0;
}
```