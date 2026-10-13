# [Make Money (MAKEMONEY)](https://www.codechef.com/problems/MAKEMONEY)

- **Difficulty Rating**: 1101
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ bags, each containing $A_i$ coins. You have the option to replace the number of coins in any bag with $X$ at a fixed cost of $C$ per operation. Your goal is to maximize the total number of coins across all bags after performing any number of operations.

## Intuition & Mathematical Observation
For each bag $i$, we have two choices:
1. **Keep the original amount**: The contribution to the total sum is $A_i$.
2. **Perform the operation**: The bag now contains $X$ coins, but we pay a cost $C$. The net contribution to the total sum is $(X - C)$.

To maximize the total sum, we should perform the operation on bag $i$ if and only if the net result of the operation is greater than the original value:
$$(X - C) > A_i$$
Rearranging this inequality, we perform the operation if:
$$(X - A_i) > C$$

If this condition holds, we replace $A_i$ with $X$ and subtract $C$ from our total. Otherwise, it is mathematically optimal to leave the bag as it is.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array of $N$ bags exactly once.
- **Space Complexity**: $O(1)$ auxiliary space, as we process each bag's value on the fly without storing the entire array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N bags, each with A_i coins (A_i <= X).
 * We can change any A_i to X at a cost of C.
 * We want to maximize (Sum of A_i) - (Total Cost).
 * 
 * For each bag i, if we perform the operation, the net change to the total sum is:
 * (X - A_i) - C.
 * 
 * If (X - A_i) > C, then performing the operation increases the total value.
 * If (X - A_i) <= C, performing the operation either decreases the total value or keeps it the same.
 * 
 * Therefore, for each bag, we should perform the operation if and only if (X - A_i) > C.
 */

void solve() {
    int N;
    long long X, C;
    cin >> N >> X >> C;
    
    long long total_value = 0;
    for (int i = 0; i < N; ++i) {
        long long A;
        cin >> A;
        
        // Check if performing the operation is beneficial
        // Benefit = (X - A) - C
        // If benefit > 0, we perform the operation.
        if ((X - A) > C) {
            total_value += X - C;
        } else {
            total_value += A;
        }
    }
    
    cout << total_value << "\n";
}

int main() {
    // Fast I/O
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