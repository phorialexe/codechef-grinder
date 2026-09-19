# [Flip the cards (FLIPCARDS)](https://www.codechef.com/problems/FLIPCARDS)

- **Difficulty Rating**: 641
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ total cards, where $X$ cards are currently face-up and the remaining $(N - X)$ cards are face-down. You want to reach a state where all cards are either face-up or face-down. The goal is to find the minimum number of flips required to achieve either of these two states.

## Intuition & Mathematical Observation
To reach a uniform state, we have two possible strategies:
1. **Make all cards face-up**: We must flip all the cards that are currently face-down. Since there are $(N - X)$ face-down cards, this requires $(N - X)$ operations.
2. **Make all cards face-down**: We must flip all the cards that are currently face-up. Since there are $X$ face-up cards, this requires $X$ operations.

To minimize the number of operations, we simply take the minimum of these two values:
$$\text{Result} = \min(X, N - X)$$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space per test case.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cards in total.
 * X cards are face-up.
 * (N - X) cards are face-down.
 * 
 * To make all cards face-up, we must flip all (N - X) face-down cards.
 * To make all cards face-down, we must flip all X face-up cards.
 * 
 * The minimum number of operations is the minimum of these two values:
 * min(X, N - X).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, x;
        cin >> n >> x;

        // Option 1: Flip all face-up cards to make everything face-down (Cost = x)
        // Option 2: Flip all face-down cards to make everything face-up (Cost = n - x)
        
        int result = min(x, n - x);
        cout << result << "\n";
    }

    return 0;
}
```