# [Spice Level (KITCHENSPICE)](https://www.codechef.com/problems/KITCHENSPICE)

- **Difficulty Rating**: 390
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to categorize a given spice level $X$ into one of three categories based on the following rules:
- **MILD**: If the spice level is less than 4 ($X < 4$).
- **MEDIUM**: If the spice level is at least 4 but less than 7 ($4 \le X < 7$).
- **HOT**: If the spice level is 7 or greater ($X \ge 7$).

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. Since the ranges are mutually exclusive and cover all possible values of $X$ (given $1 \le X \le 10$), we can use a simple `if-else if-else` ladder to determine the category:
1. First, check if $X < 4$. If true, output "MILD".
2. If the first condition fails, check if $X < 7$. Since we already know $X \ge 4$ from the first check, this correctly identifies the "MEDIUM" range ($4 \le X < 7$).
3. If both previous conditions fail, it implies $X \ge 7$, so output "HOT".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The spice level X is categorized as:
 * - MILD: X < 4
 * - MEDIUM: 4 <= X < 7
 * - HOT: X >= 7
 * 
 * Constraints: 1 <= T <= 1000, 1 <= X <= 10.
 * Time Complexity: O(T) - We perform constant time checks for each test case.
 * Space Complexity: O(1) - No extra space required.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        if (x < 4) {
            cout << "MILD" << "\n";
        } else if (x < 7) {
            cout << "MEDIUM" << "\n";
        } else {
            cout << "HOT" << "\n";
        }
    }
    
    return 0;
}
```