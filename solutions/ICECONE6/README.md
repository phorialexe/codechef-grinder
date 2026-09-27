# [IceCream Cones (ICECONE6)](https://www.codechef.com/problems/ICECONE6)

- **Difficulty Rating**: 484
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an initial amount of ice cream $X$. The ice cream melts at a rate of $Y$ units per minute. You need to determine how much ice cream remains after $N$ minutes. If the ice cream melts completely before or at the $N$-th minute, the remaining amount should be $0$.

## Intuition & Mathematical Observation
The total amount of ice cream that melts over $N$ minutes is calculated as the product of the melting rate ($Y$) and the time elapsed ($N$). 

1. **Calculate total melted**: $Melted = Y \times N$.
2. **Calculate remaining**: $Remaining = X - Melted$.
3. **Handle constraints**: Since the ice cream cannot have a negative mass, if $Remaining < 0$, the output must be $0$. This can be expressed mathematically as $\max(0, X - (Y \times N))$.

Given the constraints are small, standard integer arithmetic is sufficient, though `long long` is used to ensure safety against potential overflow in larger variations of this problem.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial amount of ice cream: X
 * Melting rate per minute: Y
 * Time elapsed: N minutes
 * Total melted amount: Y * N
 * Remaining amount: X - (Y * N)
 * 
 * Constraint: If the ice cream melts completely, the amount left cannot be negative.
 * Therefore, the result is max(0, X - (Y * N)).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, n;
        cin >> x >> y >> n;

        // Calculate total melted ice cream
        long long melted = y * n;
        
        // Calculate remaining ice cream
        long long remaining = x - melted;
        
        // If remaining is negative, it means it all melted
        if (remaining < 0) {
            cout << 0 << "\n";
        } else {
            cout << remaining << "\n";
        }
    }

    return 0;
}
```