# [Reach 5 Star (R5S)](https://www.codechef.com/problems/R5S)

- **Difficulty Rating**: 313
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef currently has a rating of $X$. After participating in a contest, their rating changes by $Y$ (where $Y$ can be positive or negative). We need to determine if Chef's new rating ($X + Y$) is at least $2000$. If the new rating is $2000$ or greater, Chef becomes a "5-star" coder.

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. We are given two integers, $X$ and $Y$. 
1. Calculate the final rating: $R = X + Y$.
2. Compare $R$ with the threshold $2000$.
3. If $R \ge 2000$, output `YES`.
4. Otherwise, output `NO`.

Since the constraints on $X$ and $Y$ are small (within the range of standard 32-bit integers), no special handling for overflow is required.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single addition and a comparison, which takes constant time regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the two integer variables $X$ and $Y$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Reach 5 Star
 * Logic:
 * Chef's current rating is X.
 * After the contest, the rating becomes X + Y.
 * Chef is 5-star if (X + Y) >= 2000.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X, Y;
    // Read the current rating and the rating change
    if (cin >> X >> Y) {
        // Check if the new rating meets the 5-star criteria
        if (X + Y >= 2000) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```