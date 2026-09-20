# [Self Defence Training (SELFDEF)](https://www.codechef.com/problems/SELFDEF)

- **Difficulty Rating**: 716
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine how many women in a given group are eligible for a self-defence training program. A woman is eligible if her age $A$ satisfies the condition $10 \le A \le 60$. Given $N$ ages for each test case, we need to count how many of these ages fall within the inclusive range $[10, 60]$.

## Intuition & Mathematical Observation
The problem is a straightforward filtering task. For each test case:
1. We iterate through the list of $N$ ages provided.
2. For every age $A$, we apply a simple conditional check: `age >= 10 && age <= 60`.
3. We maintain a counter that increments whenever the condition evaluates to `true`.
4. Since the constraints are small and the logic is linear, a simple loop is sufficient to process the input efficiently.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of women per test case. We visit each age exactly once.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the count and the current age, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Self Defence Training
 * The condition for eligibility is age A such that 10 <= A <= 60.
 * We iterate through the list of ages for each test case and count how many
 * satisfy this condition.
 * 
 * Time Complexity: O(T * N), where T is the number of test cases and N is the number of women.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        int eligible_count = 0;
        for (int i = 0; i < n; ++i) {
            int age;
            cin >> age;
            // Check if age is within the inclusive range [10, 60]
            if (age >= 10 && age <= 60) {
                eligible_count++;
            }
        }
        
        cout << eligible_count << "\n";
    }
    
    return 0;
}
```