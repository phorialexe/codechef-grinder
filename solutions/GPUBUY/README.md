# [Buying GPU (GPUBUY)](https://www.codechef.com/problems/GPUBUY)

- **Difficulty Rating**: 728
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy a GPU. The initial price of the GPU is $X$. Every month, the price increases by $Y$. Chef earns $Z$ coins every month. We need to find the minimum number of months $n$ required for Chef to have enough coins to buy the GPU. If it is impossible for Chef to ever afford the GPU, output -1.

## Intuition & Mathematical Observation
Let $n$ be the number of months.
- The price of the GPU after $n$ months is: $X + n \cdot Y$
- The total coins Chef has after $n$ months is: $n \cdot Z$

Chef can afford the GPU when:
$$n \cdot Z \ge X + n \cdot Y$$

Rearranging the inequality to solve for $n$:
$$n \cdot Z - n \cdot Y \ge X$$
$$n \cdot (Z - Y) \ge X$$

**Case 1: $Z > Y$**
If the monthly earnings are greater than the monthly price increase, the gap between Chef's savings and the GPU price closes over time. The minimum $n$ is:
$$n \ge \frac{X}{Z - Y}$$
Since $n$ must be an integer, we take the ceiling: $n = \lceil \frac{X}{Z - Y} \rceil$. Using integer arithmetic, this is calculated as `(X + diff - 1) / diff` where `diff = Z - Y`.

**Case 2: $Z \le Y$**
If the monthly earnings are less than or equal to the price increase, the gap between the price and savings will either stay the same or grow larger every month. Since $X > 0$, Chef will never be able to afford the GPU. In this case, we output -1.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef buys the GPU when: n * Z >= X + n * Y
 * Rearranging: n * (Z - Y) >= X
 * 
 * If Z > Y, n = ceil(X / (Z - Y)).
 * If Z <= Y, it is impossible to catch up, output -1.
 */

void solve() {
    long long X, Y, Z;
    cin >> X >> Y >> Z;

    if (Z <= Y) {
        cout << -1 << "\n";
    } else {
        // We need smallest n such that n * (Z - Y) >= X
        // Using integer ceiling formula: ceil(a / b) = (a + b - 1) / b
        long long diff = Z - Y;
        long long n = (X + diff - 1) / diff;
        cout << n << "\n";
    }
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