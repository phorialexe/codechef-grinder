# [Overspeeding (CCOV)](https://www.codechef.com/problems/CCOV)

- **Difficulty Rating**: 279
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a vehicle is overspeeding based on a given speed $S$. The speed limit is set at 40 km/h. If the vehicle's speed $S$ is strictly greater than 40, we must output "YES" (indicating a fine); otherwise, we output "NO".

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. We are given an integer $S$ representing the speed.
- If $S > 40$, the condition for overspeeding is met.
- If $S \le 40$, the condition is not met.

The logic follows a simple `if-else` structure:
```cpp
if (S > 40) {
    print "YES"
} else {
    print "NO"
}
```

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a single comparison and a constant number of operations regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem: CCOV
 * Strategy: Compare the input speed S with the limit 40.
 * If S > 40, Alice is fined (YES). Otherwise, she is not (NO).
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int S;
    // Read the speed input
    if (!(cin >> S)) return 0;

    // Check if speed exceeds the limit of 40
    if (S > 40) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
```