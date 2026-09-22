# [Shopping Change (SHOPCHANGE)](https://www.codechef.com/problems/SHOPCHANGE)

- **Difficulty Rating**: 526
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef goes to a shop and purchases items worth $X$ rupees. He pays the shopkeeper a 100-rupee note. The task is to calculate the amount of change Chef should receive back from the shopkeeper.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic calculation. Since Chef pays a fixed amount of 100 rupees and the cost of the items is $X$, the change received is simply the difference between the amount paid and the cost of the items.

Mathematically, the change can be represented as:
$$\text{Change} = 100 - X$$

Given the constraint $1 \le X \le 100$, the result will always be a non-negative integer, which fits perfectly within standard integer data types.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time subtraction operation.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef pays 100 rupees for items worth X rupees.
 * The change to be received is simply 100 - X.
 * Constraints: 1 <= X <= 100.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the change
        int change = 100 - x;
        
        // Output the result
        cout << change << "\n";
    }
    
    return 0;
}
```