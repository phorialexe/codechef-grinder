# [Devendra and Water Sports (DEVSPORTS)](https://www.codechef.com/problems/DEVSPORTS)

- **Difficulty Rating**: 859
- **Solved in**: 1 attempt(s)

## Problem Summary
Devendra starts with an initial amount of money $Z$. He has already spent $Y$ amount on other activities. He wishes to participate in three specific water sports with costs $A$, $B$, and $C$. We need to determine if he has enough remaining money to afford all three sports.

## Intuition & Mathematical Observation
1. **Remaining Budget**: After spending $Y$ from his initial amount $Z$, the amount Devendra has left is $Z - Y$.
2. **Required Cost**: The total cost to participate in all three sports is the sum of their individual costs: $A + B + C$.
3. **Condition**: Devendra can afford the sports if and only if his remaining budget is greater than or equal to the total cost of the sports.
   - Mathematically: $(Z - Y) \ge (A + B + C)$
4. **Data Types**: While the constraints are small, using `long long` is a good practice to prevent potential overflow issues in competitive programming environments.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations and comparisons, the complexity is constant. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$. We only use a few variables to store the input values, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Devendra starts with Z amount and has already spent Y.
 * The remaining budget is (Z - Y).
 * He wants to try three sports with costs A, B, and C.
 * The total cost for the sports is (A + B + C).
 * He can try all sports if (Z - Y) >= (A + B + C).
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long Z, Y, A, B, C;
        cin >> Z >> Y >> A >> B >> C;
        
        // Calculate remaining money after initial expenses
        long long remaining_budget = Z - Y;
        
        // Calculate total cost of the three sports
        long long total_sports_cost = A + B + C;
        
        // Check if he can afford all sports
        if (remaining_budget >= total_sports_cost) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```