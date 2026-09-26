# [Rush to Exam (RUSHTOEXAM)](https://www.codechef.com/problems/RUSHTOEXAM)

- **Difficulty Rating**: 253
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ hours available to study for an exam. In each hour, Chef can read $A$ pages. The exam requires Chef to have read at least $M$ pages. We need to determine if Chef can read enough pages within the given time to meet the requirement.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. 
1. Chef has $N$ hours and reads $A$ pages per hour. Therefore, the total number of pages Chef can read is the product of $N$ and $A$ ($N \times A$).
2. The requirement is to read at least $M$ pages.
3. We simply compare the total capacity ($N \times A$) with the requirement ($M$):
   - If $N \times A \ge M$, Chef can complete the task, so we output **"Yes"**.
   - Otherwise, Chef cannot complete the task, so we output **"No"**.

Given the constraints ($N \le 24, M \le 100, A \le 10$), the maximum possible value for $N \times A$ is 240, which easily fits within standard integer types.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and a single comparison, regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a few variables to store the input, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N hours.
 * Each hour, Chef reads A pages.
 * Total pages Chef can read = N * A.
 * Chef needs to read M pages.
 * Condition: If (N * A) >= M, output "Yes", else "No".
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M, A;
    // Read the three integers from the input
    if (!(cin >> N >> M >> A)) return 0;

    // Calculate total capacity
    long long total_capacity = N * A;

    // Check if capacity is sufficient
    if (total_capacity >= M) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}
```