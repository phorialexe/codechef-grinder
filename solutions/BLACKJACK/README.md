# [Blackjack (BLACKJACK)](https://www.codechef.com/problems/BLACKJACK)

- **Difficulty Rating**: 681
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has two cards with values $A$ and $B$. To win the game, the sum of the three cards must be exactly 21. Given $A$ and $B$, we need to find the value of the third card $X$ such that $A + B + X = 21$. If such an $X$ exists within the range $[1, 10]$, output $X$; otherwise, output $-1$.

## Intuition & Mathematical Observation
The problem states that the sum of the three cards must be 21:
$$A + B + X = 21$$

By rearranging the equation to solve for $X$, we get:
$$X = 21 - (A + B)$$

Since the third card must also be a valid card value (between 1 and 10 inclusive), we simply need to check if the calculated $X$ satisfies the condition $1 \le X \le 10$. If it does, $X$ is our answer; if it falls outside this range, it is impossible to reach 21 with a single card, so we return -1.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the inputs and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two numbers A and B. We need a third number X such that:
 * A + B + X = 21
 * Therefore, X = 21 - (A + B)
 * 
 * Constraints:
 * 1 <= A, B <= 10
 * 1 <= X <= 10
 * 
 * If the calculated X is within the range [1, 10], we output X.
 * Otherwise, it is impossible to win, so we output -1.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        int x = 21 - (a + b);
        
        // Check if the required third number is valid (between 1 and 10)
        if (x >= 1 && x <= 10) {
            cout << x << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}
```