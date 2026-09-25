# [Rectangle (RECTANGL)](https://www.codechef.com/problems/RECTANGL)

- **Difficulty Rating**: 1146
- **Solved in**: 2 attempt(s)

## Problem Summary
Given four integers representing the lengths of the four sides of a quadrilateral, determine if these sides can form a rectangle. A rectangle must have two pairs of equal opposite sides.

## Intuition & Mathematical Observation
A quadrilateral is a rectangle if and only if its sides can be grouped into two pairs of equal lengths. For example, if the sides are $a, b, c, d$, they form a rectangle if:
1. $a = b$ and $c = d$ (after sorting)
2. Or $a = c$ and $b = d$ (after sorting)
3. Or $a = d$ and $b = c$ (after sorting)

The most efficient way to check this is to **sort** the four side lengths in non-decreasing order. Once sorted, the sides will be in the order $s_0, s_1, s_2, s_3$. If the shape is a rectangle, the two smallest sides must be equal ($s_0 = s_1$) and the two largest sides must be equal ($s_2 = s_3$).

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Since we are sorting a fixed array of 4 elements, the sorting operation is $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a small, fixed-size array to store the four side lengths.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem: RECTANGL
 * Logic: A rectangle is formed if the four sides can be paired into two equal sets.
 * By sorting the four sides, we simply check if the first two are equal 
 * and the last two are equal.
 * 
 * Complexity: O(T) time, O(1) space.
 */

void solve() {
    int sides[4];
    if (!(cin >> sides[0] >> sides[1] >> sides[2] >> sides[3])) return;

    // Sort the sides to easily compare pairs
    sort(sides, sides + 4);

    // Check if the two smallest are equal and the two largest are equal
    if (sides[0] == sides[1] && sides[2] == sides[3]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```