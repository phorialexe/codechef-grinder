# [Sports Section (NEWSPAPER)](https://www.codechef.com/problems/NEWSPAPER)

- **Difficulty Rating**: 272
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given page number $X$ (where $1 \le X \le 10$) belongs to the "Sports Section" of a newspaper. The sports section is defined as the last three pages of the 10-page newspaper, which are pages 8, 9, and 10. We need to output "YES" if the page is in the sports section, and "NO" otherwise.

## Intuition & Mathematical Observation
The newspaper consists of exactly 10 pages. The sports section is explicitly defined as the final three pages:
*   Page 8
*   Page 9
*   Page 10

Mathematically, any page $X$ is part of the sports section if and only if:
$$8 \le X \le 10$$

Since the input constraints guarantee $1 \le X \le 10$, we simply need to check if $X \ge 8$. If the condition holds, we print "YES"; otherwise, we print "NO".

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison and output operation, which takes constant time.
- **Space Complexity**: $O(1)$ — We only use a single integer variable to store the input, requiring constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The newspaper has 10 pages (1 to 10).
 * The last 3 pages are 8, 9, and 10.
 * We need to check if a given page X is in the set {8, 9, 10}.
 * This is equivalent to checking if X >= 8.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // Read the page number X
    if (cin >> X) {
        // Check if the page is in the range [8, 10]
        if (X >= 8 && X <= 10) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```