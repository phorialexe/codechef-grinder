# [Mario and Bullet (BULLET)](https://www.codechef.com/problems/BULLET)

- **Difficulty Rating**: 650
- **Solved in**: 1 attempt(s)

## Problem Summary
Mario shoots a bullet at a Goomba. The bullet travels at a speed of $X$ pixels per second, and the Goomba is at a distance of $Y$ pixels. Mario wants the bullet to hit the Goomba at exactly $Z$ seconds or later. We need to calculate the minimum time Mario must wait before firing the bullet to satisfy this condition.

## Intuition & Mathematical Observation
1. **Calculate Travel Time**: The time taken for the bullet to reach the Goomba is given by the formula:
   $$\text{Travel Time} = \frac{Y}{X}$$
2. **Determine Wait Time**: Let $T_{wait}$ be the time Mario waits. The bullet hits the Goomba at time $T_{wait} + \frac{Y}{X}$. We are given the condition that this total time must be at least $Z$:
   $$T_{wait} + \frac{Y}{X} \geq Z$$
   Rearranging for $T_{wait}$:
   $$T_{wait} \geq Z - \frac{Y}{X}$$
3. **Constraint Handling**: Since Mario cannot wait for a negative amount of time, if $Z - \frac{Y}{X}$ is less than 0, the minimum wait time is 0. Otherwise, it is exactly $Z - \frac{Y}{X}$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Bullet speed = X pixels/frame (or pixels/second)
 * Distance to Goomba = Y pixels
 * Time taken for bullet to travel = Y / X seconds
 * 
 * Let T_wait be the time Mario waits before shooting.
 * The bullet hits the goomba at time (T_wait + Y/X).
 * We need (T_wait + Y/X) >= Z.
 * Therefore, T_wait >= Z - (Y/X).
 * 
 * Since T_wait cannot be negative, the minimum time is max(0, Z - (Y/X)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;

        // Calculate travel time of the bullet
        long long travel_time = y / x;

        // Calculate the required wait time
        long long wait_time = z - travel_time;

        // If wait_time is negative, Mario can shoot immediately (0 seconds)
        if (wait_time < 0) {
            cout << 0 << "\n";
        } else {
            cout << wait_time << "\n";
        }
    }

    return 0;
}
```