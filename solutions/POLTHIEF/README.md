# [Police and Thief (POLTHIEF)](https://www.codechef.com/problems/POLTHIEF)

- **Difficulty Rating**: 639
- **Solved in**: 1 attempt(s)

## Problem Summary
A policeman is at position $X$ and a thief is at position $Y$. The policeman moves at a speed of 2 units per second, while the thief moves at a speed of 1 unit per second. We need to calculate the time required for the policeman to catch the thief, assuming they both move toward each other or in the same direction to minimize the distance.

## Intuition & Mathematical Observation
The problem asks for the time taken for the policeman to catch the thief. 
- The policeman's speed is $v_p = 2$ units/sec.
- The thief's speed is $v_t = 1$ unit/sec.

Since the policeman is faster than the thief, the relative speed at which the policeman closes the gap between them is:
$$\text{Relative Speed} = |v_p - v_t| = |2 - 1| = 1 \text{ unit/sec}$$

The initial distance between them is $|X - Y|$. Since the relative speed is 1 unit per second, the time $t$ required to cover the distance $|X - Y|$ is:
$$\text{Time} = \frac{\text{Distance}}{\text{Relative Speed}} = \frac{|X - Y|}{1} = |X - Y|$$

Thus, the time taken to catch the thief is simply the absolute difference between their starting positions.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves a simple subtraction and absolute value operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Policeman is at X with speed 2.
 * Thief is at Y with speed 1.
 * The relative speed of the policeman with respect to the thief is |2 - 1| = 1 unit per second.
 * The distance between them is |X - Y|.
 * Time taken = Distance / Relative Speed = |X - Y| / 1 = |X - Y|.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // The time taken is the absolute difference between their positions
        long long time = abs(x - y);
        cout << time << "\n";
    }

    return 0;
}
```