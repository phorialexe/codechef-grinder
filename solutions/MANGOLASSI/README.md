# [Summer Time (MANGOLASSI)](https://www.codechef.com/problems/MANGOLASSI)

- **Difficulty Rating**: 242
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine whether Mamalesh will drink mango lassi based on the current temperature $X$. According to the problem statement, Mamalesh drinks mango lassi if and only if the temperature is strictly greater than 35 degrees Celsius. We need to output "YES" if the condition is met, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. We are given an integer $X$ representing the temperature. The logic follows a simple boolean condition:
- If $X > 35$, the output should be `YES`.
- Otherwise (if $X \le 35$), the output should be `NO`.

Since the input constraints are small and the logic is a single comparison, we can implement this using a simple `if-else` statement.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison and output operation, which takes constant time regardless of the input value.
- **Space Complexity**: $O(1)$ — We only use a single integer variable to store the input, requiring constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Summer Time
 * Logic: Mamalesh drinks mango lassi if temperature X > 35.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    // Check if temperature is strictly greater than 35
    if (X > 35) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}
```