# [It is My Serve (MYSERVE)](https://www.codechef.com/problems/MYSERVE)

- **Difficulty Rating**: 691
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game of tennis, Alice and Bob take turns serving. The rule is that each player serves for 2 consecutive points before the serve switches to the other player. Alice always starts the first serve. Given the current score $P$ (Alice's points) and $Q$ (Bob's points), determine whose turn it is to serve.

## Intuition & Mathematical Observation
The total number of points played at any given time is $S = P + Q$. Since the serve switches every 2 points, we can group the points into blocks of 2:

*   **Points 0, 1**: $S/2 = 0$ (Even) $\rightarrow$ Alice's turn
*   **Points 2, 3**: $S/2 = 1$ (Odd) $\rightarrow$ Bob's turn
*   **Points 4, 5**: $S/2 = 2$ (Even) $\rightarrow$ Alice's turn
*   **Points 6, 7**: $S/2 = 3$ (Odd) $\rightarrow$ Bob's turn

By calculating `turn_group = (P + Q) / 2`, we can determine the server based on the parity of the result:
- If `turn_group` is **even**, it is **Alice's** turn.
- If `turn_group` is **odd**, it is **Bob's** turn.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The total number of points played is S = P + Q.
 * The service changes every 2 points.
 * - Points 0, 1: Alice serves (S/2 = 0)
 * - Points 2, 3: Bob serves (S/2 = 1)
 * - Points 4, 5: Alice serves (S/2 = 2)
 * - Points 6, 7: Bob serves (S/2 = 3)
 * 
 * We can observe that if (S / 2) is even, it is Alice's turn.
 * If (S / 2) is odd, it is Bob's turn.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p, q;
        cin >> p >> q;
        
        long long total_points = p + q;
        long long turn_group = total_points / 2;
        
        if (turn_group % 2 == 0) {
            cout << "Alice" << "\n";
        } else {
            cout << "Bob" << "\n";
        }
    }
    
    return 0;
}
```