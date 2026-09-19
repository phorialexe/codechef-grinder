# [Enough Space (ENSPACE)](https://www.codechef.com/problems/ENSPACE)

- **Difficulty Rating**: 317
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a storage capacity of $N$ GB. He intends to store $X$ files of 1 GB each and $Y$ files of 2 GB each. We need to determine if the total storage required by these files is less than or equal to the available capacity $N$. If it is possible to store all files, output "YES"; otherwise, output "NO".

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic comparison. 
1. Each of the $X$ files occupies 1 GB, contributing $X \times 1$ to the total size.
2. Each of the $Y$ files occupies 2 GB, contributing $Y \times 2$ to the total size.
3. The total space required is calculated as:
   $$\text{Total Size} = X + 2Y$$
4. The condition for success is:
   $$\text{Total Size} \le N$$

Since the constraints are small ($N, X, Y \le 100$), the calculation will not overflow standard integer types, and the logic can be implemented using a simple `if-else` statement.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N GB of space.
 * He has X files of 1 GB each and Y files of 2 GB each.
 * Total size required = (X * 1) + (Y * 2).
 * Chef can save the files if (X + 2 * Y) <= N.
 * 
 * Constraints:
 * T <= 100
 * N, X, Y <= 100
 * The maximum possible size is 100 + 2 * 100 = 300, which fits in a standard int.
 * Time complexity per test case: O(1)
 * Space complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;
        
        // Calculate total size required
        long long total_size = x + (2 * y);
        
        // Check if total size is less than or equal to available space
        if (total_size <= n) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```