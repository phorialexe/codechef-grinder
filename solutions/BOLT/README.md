# [World Record (BOLT)](https://www.codechef.com/problems/BOLT)

- **Difficulty Rating**: 1128
- **Solved in**: 1 attempt(s)

## Problem Summary
Usain Bolt's world record for the 100m sprint is 9.58 seconds. Chef wants to beat this record. Given three factors $k_1, k_2, k_3$ that affect his speed and his base speed $v$, his final speed is calculated as $v_{final} = k_1 \times k_2 \times k_3 \times v$. We need to determine if the time taken to cover 100 meters, rounded to two decimal places, is strictly less than 9.58 seconds.

## Intuition & Mathematical Observation
1. **Speed Calculation**: The final speed is simply the product of the given constants and the base speed: $v_{final} = k_1 \cdot k_2 \cdot k_3 \cdot v$.
2. **Time Calculation**: The time taken to cover 100 meters is $T = \frac{100}{v_{final}}$.
3. **Handling Precision**: The problem requires the time to be rounded to two decimal places. A direct comparison `round(T, 2) < 9.58` can be tricky due to floating-point representation errors.
4. **The Epsilon Trick**: Instead of using a rounding function, we can use a threshold. A value rounds to 9.58 if it is $\ge 9.575$. Therefore, to be strictly less than 9.58 after rounding, the calculated time $T$ must be strictly less than $9.575$. This avoids potential issues with `double` precision and built-in rounding functions.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations. Total complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The final speed of Chef is v_final = k1 * k2 * k3 * v.
 * The time taken is T = 100 / v_final.
 * We need to check if T < 9.58.
 * 
 * Note on rounding:
 * The problem states the time is rounded to 2 decimal places.
 * To avoid floating point precision issues, we can compare the rounded value.
 * A common way to round to 2 decimal places is to add a small epsilon 
 * (like 1e-9) and then check the condition.
 * 
 * Specifically, if we want to check if round(T, 2) < 9.58:
 * This is equivalent to checking if T < 9.575.
 * Why? Because any value < 9.575 will round down to 9.57 or less,
 * and any value >= 9.575 will round up to 9.58 or more.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        double k1, k2, k3, v;
        cin >> k1 >> k2 >> k3 >> v;

        // Calculate final speed
        double final_speed = k1 * k2 * k3 * v;
        
        // Calculate time taken
        double time_taken = 100.0 / final_speed;

        // We need to check if round(time_taken, 2) < 9.58.
        // Using a small epsilon to handle floating point inaccuracies.
        // The threshold for rounding to 9.58 is 9.575.
        // If time_taken < 9.575, it rounds to <= 9.57, which is < 9.58.
        if (time_taken < 9.575) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```