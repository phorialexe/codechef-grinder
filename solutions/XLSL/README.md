# [Clothing Store (XLSL)](https://www.codechef.com/problems/XLSL)

- **Difficulty Rating**: 947
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given the inventory of three shirt sizes: Small ($X$), Large ($Y$), and Extra Large ($Z$). We also have the demand for these sizes: $A$ (Small), $B$ (Large), and $C$ (Extra Large). 

The conversion rules are:
1. An **XL** shirt can be used for an **XL**, **L**, or **S** person.
2. A **Large** shirt can be used for a **Large** or **S** person.
3. A **Small** shirt can only be used for a **Small** person.

The goal is to maximize the total number of satisfied customers.

## Intuition & Mathematical Observation
To maximize the number of satisfied customers, we must prioritize the most "restrictive" demands first. Since an XL shirt is the most versatile (it can satisfy any demand), we should use it only when necessary.

1. **Prioritize XL Demand**: Since XL shirts are the only ones that can satisfy XL demand, we use the available $Z$ shirts to satisfy $C$ first. Any leftover $Z$ shirts become available for $L$ or $S$ demands.
2. **Prioritize L Demand**: After satisfying XL demand, we combine the remaining XL shirts with the existing $Y$ shirts to satisfy the $B$ demand. Any leftover shirts from this pool can then be used for $S$ demand.
3. **Satisfy S Demand**: Finally, we combine the remaining shirts (from the $L$ and $XL$ pools) with the original $X$ shirts to satisfy the $A$ demand.

This greedy approach works because we always reserve the most specific shirts for their intended size and only use "larger" shirts for "smaller" people when the specific size is exhausted.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Strategy:
 * 1. Satisfy XL demand (C) using available XL shirts (Z).
 * 2. Satisfy L demand (B) using available L shirts (Y) and remaining XL shirts.
 * 3. Satisfy S demand (A) using available S shirts (X) and remaining L/XL shirts.
 */

void solve() {
    long long X, Y, Z, A, B, C;
    cin >> X >> Y >> Z >> A >> B >> C;

    // 1. Satisfy XL demand
    long long happy_xl = min(Z, C);
    long long rem_z = Z - happy_xl;

    // 2. Satisfy L demand using L shirts and leftover XL shirts
    long long available_l = Y + rem_z;
    long long happy_l = min(available_l, B);
    long long rem_l = available_l - happy_l;

    // 3. Satisfy S demand using S shirts and leftover L/XL shirts
    long long available_s = X + rem_l;
    long long happy_s = min(available_s, A);

    cout << happy_xl + happy_l + happy_s << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```