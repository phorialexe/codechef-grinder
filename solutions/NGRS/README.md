# [50-50 Rule (NGRS)](https://www.codechef.com/problems/NGRS)

- **Difficulty Rating**: 524
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine a student's grade based on two criteria: attendance ($X$) and marks ($Y$). The grading rules are strictly hierarchical:
1. If the attendance $X$ is less than 50, the student receives grade **'Z'**.
2. If the attendance $X$ is 50 or greater, but the marks $Y$ are less than 50, the student receives grade **'F'**.
3. If both the attendance $X$ and the marks $Y$ are 50 or greater, the student receives grade **'A'**.

## Intuition & Mathematical Observation
The problem can be solved using simple conditional (`if-else`) logic. Since the rules are dependent on each other, the order of evaluation is crucial:
- We must check the attendance condition first. If $X < 50$, the marks $Y$ do not matter, and the output is immediately 'Z'.
- If the first condition fails (meaning $X \ge 50$), we then check the marks. If $Y < 50$, the output is 'F'.
- If both conditions fail (meaning $X \ge 50$ and $Y \ge 50$), the output is 'A'.

This approach ensures that we correctly categorize every possible input pair $(X, Y)$ according to the problem statement.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only store the input variables $X$ and $Y$ and do not use any additional data structures that scale with input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grading logic is defined as:
 * 1. If attendance (X) < 50: Grade is 'Z'.
 * 2. Else if marks (Y) < 50: Grade is 'F'.
 * 3. Otherwise: Grade is 'A'.
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
        int x, y;
        cin >> x >> y;
        
        if (x < 50) {
            cout << "Z" << "\n";
        } else if (y < 50) {
            cout << "F" << "\n";
        } else {
            cout << "A" << "\n";
        }
    }
    
    return 0;
}
```