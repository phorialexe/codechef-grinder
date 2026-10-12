# [Chef and Vacation Transportation (CHEFTRANS)](https://www.codechef.com/problems/CHEFTRANS)

- **Difficulty Rating**: 855
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is planning a trip and has two ways to reach his destination:
1. **Plane + Bus**: Takes $X$ minutes for the plane and $Y$ minutes for the bus. Total time = $X + Y$.
2. **Train**: Takes $Z$ minutes.

We need to determine which option is faster. If the plane and bus combination is faster, output `PLANEBUS`. If the train is faster, output `TRAIN`. If both take the same amount of time, output `EQUAL`.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. We are given three integers $X, Y,$ and $Z$:
- Calculate the total time for the first option: $T_1 = X + Y$.
- The time for the second option is $T_2 = Z$.
- Compare $T_1$ and $T_2$:
    - If $T_1 < T_2$, the plane and bus are faster.
    - If $T_2 < T_1$, the train is faster.
    - If $T_1 = T_2$, both are equal.

**Note on Constraints**: Since $X, Y, Z$ can be up to $10^9$, their sum can reach $2 \times 10^9$. While this fits within a standard 32-bit signed integer (which goes up to $\approx 2.14 \times 10^9$), using `long long` is a best practice in competitive programming to prevent potential overflow issues.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations and comparisons, the time complexity is constant. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated sums.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: CHEFTRANS
 * The problem asks us to compare the time taken by two travel options:
 * Option 1 (Plane + Bus): X + Y minutes
 * Option 2 (Train): Z minutes
 * 
 * Constraints: X, Y, Z up to 10^9.
 * The sum X + Y can be up to 2 * 10^9, which fits within a standard 32-bit signed integer,
 * but using long long is safer and good practice in competitive programming to avoid overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        long long plane_bus_time = x + y;
        long long train_time = z;
        
        if (plane_bus_time < train_time) {
            cout << "PLANEBUS" << "\n";
        } else if (train_time < plane_bus_time) {
            cout << "TRAIN" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }
    
    return 0;
}
```