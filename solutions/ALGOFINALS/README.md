# [Algomaniac Finals (ALGOFINALS)](https://www.codechef.com/problems/ALGOFINALS)

- **Difficulty Rating**: 279
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a given integer $X$ represents the date of the Algomaniac finals. According to the problem statement, the finals are held on March 17th. We need to output "YAY" if the input $X$ is equal to 17, and "NO" otherwise.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. Since the date of the finals is fixed at 17, we simply need to compare the input variable $X$ with the constant 17. 
- If $X = 17$, the condition is satisfied.
- For any other integer value of $X$, the condition is not satisfied.

This can be implemented using a simple `if-else` statement.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison and output operation, which takes constant time regardless of the input value.
- **Space Complexity**: $O(1)$ — We only use a single integer variable to store the input, requiring constant auxiliary space.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * The problem asks to check if the given day X is the day of the Algomaniac finals,
 * which is March 17.
 * 
 * Logic:
 * If X == 17, print "YAY".
 * Otherwise, print "NO".
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // Read the input day
    if (!(cin >> X)) return 0;

    // Check if the day is 17
    if (X == 17) {
        cout << "YAY" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
```