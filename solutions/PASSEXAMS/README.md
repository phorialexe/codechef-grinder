# [Passing Exams (PASSEXAMS)](https://www.codechef.com/problems/PASSEXAMS)

- **Difficulty Rating**: 480
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef takes three exams with scores $X$, $Y$, and $Z$. To pass the overall assessment, Chef must score at least 50 marks in at least two out of the three exams. Given the three scores, determine if Chef passes or fails.

## Intuition & Mathematical Observation
The problem requires checking a condition across three variables. 
1. We define a "passing" exam as one where the score is $\ge 50$.
2. We can maintain a counter variable initialized to 0.
3. For each of the three inputs ($X, Y, Z$), we increment the counter if the score is greater than or equal to 50.
4. Finally, we check if the counter is greater than or equal to 2. If true, output "Yes"; otherwise, output "No".

This approach is efficient and directly maps to the problem requirements without needing complex conditional logic.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons ($O(1)$).
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the scores and the counter, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Passing Exams
 * Logic:
 * Chef needs to score >= 50 in at least 2 out of 3 exams.
 * We can count how many exams have a score >= 50.
 * If the count is >= 2, output "Yes", otherwise "No".
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        
        int count = 0;
        // Check each exam score
        if (x >= 50) count++;
        if (y >= 50) count++;
        if (z >= 50) count++;
        
        // Determine if Chef passed
        if (count >= 2) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}
```