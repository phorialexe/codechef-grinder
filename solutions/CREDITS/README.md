# [Complete the credits (CREDITS)](https://www.codechef.com/problems/CREDITS)

- **Difficulty Rating**: 809
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to categorize a student's credit count ($X$) into one of three categories based on specific thresholds:
- If the credits are strictly greater than 65, the student is in **"Overload"**.
- If the credits are strictly less than 35, the student is in **"Underload"**.
- If the credits are between 35 and 65 (inclusive), the student is in **"Normal"**.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. Since the thresholds are clearly defined, we can use simple `if-else if-else` statements to check the value of $X$:
1. Check if $X > 65$.
2. Check if $X < 35$.
3. If neither condition is met, the value must fall within the range $[35, 65]$, which corresponds to "Normal".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a single variable to store the input for each test case.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Complete the credits
 * Logic:
 * - If X > 65, output "Overload"
 * - If X < 35, output "Underload"
 * - Otherwise, output "Normal"
 * 
 * Time Complexity: O(T), where T is the number of test cases.
 * Space Complexity: O(1), as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x;
        cin >> x;
        
        if (x > 65) {
            cout << "Overload" << "\n";
        } else if (x < 35) {
            cout << "Underload" << "\n";
        } else {
            cout << "Normal" << "\n";
        }
    }
    
    return 0;
}
```