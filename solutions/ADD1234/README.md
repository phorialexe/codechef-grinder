# [Adding 123 to 4 (ADD1234)](https://www.codechef.com/problems/ADD1234)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $X$ pieces of value 1, $Y$ pieces of value 2, and $Z$ pieces of value 3, determine the maximum number of pairs that can be formed such that the sum of each pair is exactly 4.

## Intuition & Mathematical Observation
To form a sum of 4 using the available numbers $\{1, 2, 3\}$, we have two distinct ways to create a pair:
1. **Pairing (1, 3):** A 1 and a 3 sum to 4. The number of such pairs we can form is limited by the smaller count of the two available numbers. Thus, we can form $\min(X, Z)$ pairs.
2. **Pairing (2, 2):** Two 2s sum to 4. Since we need two 2s for every pair, the number of such pairs is $\lfloor Y / 2 \rfloor$.

Since these two methods of forming pairs are independent (they use different sets of numbers), the total number of pairs is simply the sum of the pairs formed by each method:
$$\text{Total Pairs} = \min(X, Z) + \lfloor Y / 2 \rfloor$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations and comparisons. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X pieces of 1, Y pieces of 2, and Z pieces of 3.
 * We want to form pairs that sum to 4.
 * Possible combinations to get 4:
 * 1. (1, 3): We can form min(X, Z) pairs.
 * 2. (2, 2): We can form floor(Y / 2) pairs.
 * 
 * Total pairs = min(X, Z) + (Y / 2)
 */

void solve() {
    long long X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return;
    
    // Pairs of (1, 3)
    long long pairs13 = min(X, Z);
    
    // Pairs of (2, 2)
    long long pairs22 = Y / 2;
    
    cout << (pairs13 + pairs22) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}
```