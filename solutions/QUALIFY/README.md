# [Qualify the round (QUALIFY)](https://www.codechef.com/problems/QUALIFY)

- **Difficulty Rating**: 594
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef participates in a contest where there are two types of problems:
- **Easy problems**: Worth 1 point each.
- **Hard problems**: Worth 2 points each.

Given the number of easy problems solved ($A$), the number of hard problems solved ($B$), and the minimum score required to qualify ($X$), determine if Chef qualifies for the next round. Chef qualifies if their total score is greater than or equal to $X$.

## Intuition & Mathematical Observation
The total score is calculated by summing the points from easy and hard problems:
$$\text{Total Score} = (A \times 1) + (B \times 2)$$

To determine if Chef qualifies, we simply compare the calculated `Total Score` against the threshold `X`:
- If `Total Score` $\ge X$, output "Qualify".
- Otherwise, output "NotQualify".

Since the constraints are small ($A, B, X \le 100$), standard integer types are sufficient, though `long long` is used here as a best practice to prevent potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and a comparison.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of extra space to store the input variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Qualify the round
 * Logic:
 * Easy problems are worth 1 point, Hard problems are worth 2 points.
 * Total score = (A * 1) + (B * 2).
 * Chef qualifies if Total score >= X.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, a, b;
        cin >> x >> a >> b;
        
        // Calculate total score
        long long total_score = (a * 1) + (b * 2);
        
        if (total_score >= x) {
            cout << "Qualify" << "\n";
        } else {
            cout << "NotQualify" << "\n";
        }
    }
    
    return 0;
}
```