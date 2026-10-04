# [Drunk Alcoholic (DRUNKALK)](https://www.codechef.com/problems/DRUNKALK)

- **Difficulty Rating**: 874
- **Solved in**: 1 attempt(s)

## Problem Summary
Faizal moves in a specific pattern every second:
1. In the first second, he moves **3 steps forward**.
2. In the second second, he moves **1 step backward**.
3. This pattern repeats indefinitely.

Given an integer $k$, we need to calculate his total displacement from the starting position after $k$ seconds.

## Intuition & Mathematical Observation
By observing the movement pattern, we can see that every 2 seconds form a complete cycle:
* **Cycle (2 seconds):** $+3$ (forward) $- 1$ (backward) $= +2$ net displacement.

We can derive the position based on whether $k$ is even or odd:

* **If $k$ is even:**
  There are exactly $k/2$ full cycles.
  $$\text{Position} = (k/2) \times 2 = k$$

* **If $k$ is odd:**
  There are $(k-1)/2$ full cycles, followed by one final forward step of $+3$.
  $$\text{Position} = ((k-1)/2 \times 2) + 3 = (k-1) + 3 = k + 2$$

**Examples:**
- $k=1$: Odd $\rightarrow 1+2 = 3$
- $k=2$: Even $\rightarrow 2$
- $k=3$: Odd $\rightarrow 3+2 = 5$
- $k=4$: Even $\rightarrow 4$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses a simple mathematical formula. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In every 2 seconds (a cycle), Faizal moves 3 steps forward and 1 step backward.
 * Net displacement per 2 seconds = 3 - 1 = 2 steps.
 * 
 * If k is even:
 * There are k/2 full cycles.
 * Position = (k/2) * 2 = k.
 * 
 * If k is odd:
 * There are (k-1)/2 full cycles, plus one final forward step.
 * Position = ((k-1)/2) * 2 + 3 = (k-1) + 3 = k + 2.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long k;
        cin >> k;
        
        if (k == 0) {
            cout << 0 << "\n";
        } else if (k % 2 == 0) {
            // Even number of seconds: k/2 cycles of +2 displacement
            cout << k << "\n";
        } else {
            // Odd number of seconds: (k-1)/2 cycles of +2, plus 3 forward
            cout << (k + 2) << "\n";
        }
    }
    return 0;
}
```