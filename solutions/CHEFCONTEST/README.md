# [Chef and Contest (CHEFCONTEST)](https://www.codechef.com/problems/CHEFCONTEST)

- **Difficulty Rating**: 872
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef and Chefina are participating in a contest. Chef solves a problem in $X$ minutes and incurs $P$ penalties, while Chefina solves a problem in $Y$ minutes and incurs $Q$ penalties. Each penalty adds 10 minutes to the total time taken. We need to determine who finishes with a lower total time, or if it is a draw.

## Intuition & Mathematical Observation
The total time taken by a participant is calculated as:
$$\text{Total Time} = \text{Time taken} + (\text{Number of penalties} \times 10)$$

By calculating this value for both Chef and Chefina, we can directly compare the two results:
1. If `Chef_Total < Chefina_Total`, Chef wins.
2. If `Chefina_Total < Chef_Total`, Chefina wins.
3. If `Chef_Total == Chefina_Total`, it is a draw.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and calculated totals.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem: CHEFCONTEST
 * Logic:
 * Chef's penalty = X + P * 10
 * Chefina's penalty = Y + Q * 10
 * Compare the two and output the winner.
 */

void solve() {
    int X, Y, P, Q;
    if (!(cin >> X >> Y >> P >> Q)) return;

    int chef_penalty = X + (P * 10);
    int chefina_penalty = Y + (Q * 10);

    if (chef_penalty < chefina_penalty) {
        cout << "Chef" << endl;
    } else if (chefina_penalty < chef_penalty) {
        cout << "Chefina" << endl;
    } else {
        cout << "Draw" << endl;
    }
}

int main() {
    // Optimize I/O operations
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