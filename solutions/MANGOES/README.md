# [The Mango Truck (MANGOES)](https://www.codechef.com/problems/MANGOES)

- **Difficulty Rating**: 482
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given three integers:
- $X$: The weight of a single mango.
- $Y$: The weight of the truck itself.
- $Z$: The maximum weight capacity of the bridge.

The goal is to find the maximum number of mangoes ($N$) that can be loaded onto the truck such that the total weight (truck + mangoes) does not exceed the bridge's capacity ($Z$).

## Intuition & Mathematical Observation
The total weight on the bridge is the sum of the truck's weight and the weight of all mangoes. If we load $N$ mangoes, the total weight is:
$$\text{Total Weight} = (N \times X) + Y$$

We are constrained by the bridge capacity $Z$:
$$(N \times X) + Y \le Z$$

To solve for $N$:
1. Subtract the truck's weight from both sides: $N \times X \le Z - Y$
2. Divide by the weight of a single mango: $N \le \frac{Z - Y}{X}$

Since $N$ must be an integer, we take the floor of the result:
$$N = \lfloor \frac{Z - Y}{X} \rfloor$$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let N be the number of mangoes.
 * The total weight is (N * X) + Y.
 * The bridge can withstand weight Z.
 * We need: (N * X) + Y <= Z
 * N * X <= Z - Y
 * N <= (Z - Y) / X
 * Since we want the maximum number of mangoes, N = floor((Z - Y) / X).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        
        // Calculate the remaining capacity for mangoes
        int remaining_capacity = z - y;
        
        // Calculate maximum number of mangoes
        // Since X >= 1, we don't need to worry about division by zero.
        int max_mangoes = remaining_capacity / x;
        
        cout << max_mangoes << "\n";
    }
    
    return 0;
}
```