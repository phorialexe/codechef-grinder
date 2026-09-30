# [Water Park (SPCP1)](https://www.codechef.com/problems/SPCP1)

- **Difficulty Rating**: 485
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to enter a water park. The park has specific entry requirements based on weight ($W$) and height ($H$):
1. A person's weight must be at most $W$ kg.
2. A person's height must be at least $H$ cm.

Given Chef's weight is **60 kg** and his height is **130 cm**, determine if he is allowed to enter the water park.

## Intuition & Mathematical Observation
The problem provides two fixed values for Chef and two variable constraints from the input:
- **Chef's Weight ($C_W$)**: 60
- **Chef's Height ($C_H$)**: 130

For Chef to enter, both conditions must be satisfied simultaneously:
1. $C_W \le W$ (Chef's weight is less than or equal to the maximum allowed weight $W$).
2. $C_H \ge H$ (Chef's height is greater than or equal to the minimum required height $H$).

If both `60 <= W` and `130 >= H` evaluate to true, output `YES`; otherwise, output `NO`.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a constant number of arithmetic and logical comparisons regardless of the input values.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and constants.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's weight = 60 kg
 * Chef's height = 130 cm
 * Condition for entry:
 * 1. Weight <= W
 * 2. Height >= H
 * 
 * We need to check if 60 <= W AND 130 >= H.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long W, H;
    // Read the weight limit W and height limit H
    if (cin >> W >> H) {
        // Chef's stats
        long long chefWeight = 60;
        long long chefHeight = 130;

        // Check conditions: 
        // Chef's weight must be <= W AND Chef's height must be >= H
        if (chefWeight <= W && chefHeight >= H) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```