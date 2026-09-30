# [Lucky Number (LUCKYNUM)](https://www.codechef.com/problems/LUCKYNUM)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $A$, $B$, and $C$, determine if at least one of these integers is equal to $7$. If any of the numbers are $7$, output `YES`; otherwise, output `NO`.

## Intuition & Mathematical Observation
The problem asks for a simple conditional check. Since we are provided with exactly three integers, we can use the logical OR (`||`) operator in C++ to verify if any of the variables $A$, $B$, or $C$ satisfy the condition $x = 7$. 

The logic follows:
- If $A == 7$ OR $B == 7$ OR $C == 7$, the condition is satisfied.
- Otherwise, it is not.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the three integers regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: LUCKYNUM
 * Logic: Check if any of the three input integers A, B, or C is equal to 7.
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few integer variables.
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        // Check if any of the digits is 7
        if (a == 7 || b == 7 || c == 7) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```