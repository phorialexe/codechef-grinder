# [Chess Format (CHSFORMT)](https://www.codechef.com/problems/CHSFORMT)

- **Difficulty Rating**: 844
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to categorize a chess game based on the total duration of the game, which is the sum of the bullet time ($a$) and the blitz time ($b$). The categories are defined as follows:
- **Bullet**: Total time $< 3$
- **Blitz**: $3 \le$ Total time $\le 10$
- **Rapid**: $11 \le$ Total time $\le 60$
- **Classical**: Total time $> 60$

We need to output the corresponding category index (1, 2, 3, or 4) for each test case.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. By calculating the sum $S = a + b$, we can map the result directly to the specified ranges using `if-else` statements. Since the constraints on $a$ and $b$ are small, a standard integer type is sufficient, though `long long` is used here for safety.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic and comparison operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the sum, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chess Format
 * Logic:
 * Calculate sum = a + b.
 * Apply the conditional logic provided:
 * 1) Bullet if sum < 3
 * 2) Blitz if 3 <= sum <= 10
 * 3) Rapid if 11 <= sum <= 60
 * 4) Classical if sum > 60
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        long long sum = a + b;
        
        if (sum < 3) {
            cout << 1 << "\n";
        } else if (sum >= 3 && sum <= 10) {
            cout << 2 << "\n";
        } else if (sum >= 11 && sum <= 60) {
            cout << 3 << "\n";
        } else {
            cout << 4 << "\n";
        }
    }
    
    return 0;
}
```