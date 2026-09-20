# [Mario and Transformation (TRANSFORM)](https://www.codechef.com/problems/TRANSFORM)
- **Difficulty Rating**: 649
- **Solved in**: 1 attempt(s)

## Problem Summary
Mario starts in a `NORMAL` state. When he eats $X$ mushrooms, his state changes based on the number of mushrooms consumed. The transformation follows a repeating cycle:
- 0 mushrooms: `NORMAL`
- 1 mushroom: `HUGE`
- 2 mushrooms: `SMALL`
- 3 mushrooms: `NORMAL`
- 4 mushrooms: `HUGE`
- ... and so on.

Given $X$, we need to determine Mario's final state.

## Intuition & Mathematical Observation
By observing the sequence of states:
1. $X=0 \rightarrow$ `NORMAL`
2. $X=1 \rightarrow$ `HUGE`
3. $X=2 \rightarrow$ `SMALL`
4. $X=3 \rightarrow$ `NORMAL`
5. $X=4 \rightarrow$ `HUGE`
6. $X=5 \rightarrow$ `SMALL`

We can see that the states repeat every 3 mushrooms. This is a classic modular arithmetic problem. By calculating $X \pmod 3$, we can map the result directly to the state:
- If $X \pmod 3 = 0$, the state is `NORMAL`.
- If $X \pmod 3 = 1$, the state is `HUGE`.
- If $X \pmod 3 = 2$, the state is `SMALL`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time modulo operation and a conditional check.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the remainder.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The transformation cycle repeats every 3 mushrooms:
 * X % 3 == 0 -> NORMAL
 * X % 3 == 1 -> HUGE
 * X % 3 == 2 -> SMALL
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x;
        cin >> x;
        
        int remainder = x % 3;
        
        if (remainder == 0) {
            cout << "NORMAL" << "\n";
        } else if (remainder == 1) {
            cout << "HUGE" << "\n";
        } else {
            cout << "SMALL" << "\n";
        }
    }
    
    return 0;
}
```