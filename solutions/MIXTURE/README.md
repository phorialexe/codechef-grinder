# [Which Mixture (MIXTURE)](https://www.codechef.com/problems/MIXTURE)

- **Difficulty Rating**: 841
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ (representing the amount of solid) and $B$ (representing the amount of liquid) in a mixture, we need to classify the mixture into one of three categories:
1. **Solution**: If both $A > 0$ and $B > 0$.
2. **Solid**: If $B = 0$ (and $A > 0$).
3. **Liquid**: If $A = 0$ (and $B > 0$).

It is guaranteed that $A + B > 0$, meaning the mixture cannot be empty.

## Intuition & Mathematical Observation
The problem is a straightforward conditional logic task. Since the constraints guarantee that $A$ and $B$ are non-negative and their sum is greater than zero, we can determine the state of the mixture using simple `if-else` statements:

1. **Check for Solution**: If both $A$ and $B$ are strictly greater than $0$, the mixture contains both components.
2. **Check for Solid**: If $B$ is $0$, the mixture consists entirely of solid.
3. **Check for Liquid**: If $A$ is $0$, the mixture consists entirely of liquid.

Because the problem guarantees $A+B > 0$, we do not need to handle the case where both $A$ and $B$ are $0$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and perform the logic.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given A (solid) and B (liquid):
 * 1. If A > 0 and B > 0, it's a "Solution".
 * 2. If B == 0, it's a "Solid".
 * 3. If A == 0, it's a "Liquid".
 * 
 * Constraints: 0 <= A, B <= 100, A + B > 0.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        if (a > 0 && b > 0) {
            cout << "Solution" << "\n";
        } else if (b == 0) {
            cout << "Solid" << "\n";
        } else if (a == 0) {
            cout << "Liquid" << "\n";
        }
    }
    
    return 0;
}
```