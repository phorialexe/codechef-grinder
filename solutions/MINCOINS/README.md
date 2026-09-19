# [Minimum number of coins (MINCOINS)](https://www.codechef.com/problems/MINCOINS)

- **Difficulty Rating**: 711
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an amount $X$, determine the minimum number of coins required to represent $X$ using only 5-rupee and 10-rupee coins. If it is impossible to represent $X$ with these denominations, output -1.

## Intuition & Mathematical Observation
To minimize the total number of coins, we must prioritize the coin with the largest denomination (10-rupee coins).

1. **Divisibility Check**: Since both denominations (5 and 10) are multiples of 5, any amount $X$ that is not divisible by 5 cannot be formed. In such cases, the answer is -1.
2. **Greedy Approach**:
   - If $X$ is divisible by 10, we can represent it entirely using $X/10$ coins of 10 rupees.
   - If $X$ is not divisible by 10 but is divisible by 5, there will be a remainder of 5. We use as many 10-rupee coins as possible ($X/10$ integer division) and add exactly one 5-rupee coin to cover the remainder.
   - Mathematically, the number of coins is $\lceil X/10 \rceil$ if $X$ is a multiple of 5.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have coins of denominations 5 and 10.
 * To minimize the number of coins, we should use as many 10-rupee coins as possible.
 * 
 * Logic:
 * 1. If X is not divisible by 5, it is impossible to form X using only 5s and 10s. Return -1.
 * 2. If X is divisible by 5:
 *    - We want to maximize the number of 10s.
 *    - Number of 10s = X / 10.
 *    - Remainder = X % 10.
 *    - If remainder is 0, we need (X / 10) coins.
 *    - If remainder is 5, we need (X / 10) + 1 coins (one 5-rupee coin).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        if (x % 5 != 0) {
            cout << -1 << "\n";
        } else {
            // Calculate number of 10s
            int coins = x / 10;
            // If there is a remainder of 5, add one 5-rupee coin
            if (x % 10 != 0) {
                coins += 1;
            }
            cout << coins << "\n";
        }
    }

    return 0;
}
```