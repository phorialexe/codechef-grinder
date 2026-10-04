# [Independence Day 101 (INDEPENDENCE)](https://www.codechef.com/problems/INDEPENDENCE)

- **Difficulty Rating**: 771
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $A, B,$ and $C$ representing the number of strips of three different colors, determine if it is possible to arrange all these strips in a single line such that no two adjacent strips have the same color.

## Intuition & Mathematical Observation
To determine if a valid arrangement exists, we focus on the color with the highest frequency. Let the counts be sorted such that $x \le y \le z$, where $z$ is the maximum count.

1.  **The Pigeonhole Principle**: If we place the $z$ strips of the most frequent color in a line, they create $z-1$ gaps between them that *must* be filled by the other colors to prevent adjacency.
    *   Example: `Z _ Z _ Z` (3 Zs create 2 gaps).
2.  **The Condition**: We have $x + y$ strips of the other two colors available to fill these $z-1$ gaps. Therefore, a valid arrangement is possible if and only if:
    $$(x + y) \ge (z - 1)$$
3.  **Rearranging**: This inequality can be rewritten as $x + y + 1 \ge z$. If this condition holds, we can distribute the remaining strips into the gaps created by the most frequent color, ensuring no two identical colors are adjacent.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Sorting an array of 3 elements takes constant time, and the arithmetic operations are also constant.
- **Space Complexity**: $O(1)$ as we only use a fixed-size array to store the three color counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three colors with counts A, B, and C. We need to arrange them in a line
 * such that no two adjacent strips have the same color.
 * 
 * Let the counts be sorted such that x <= y <= z.
 * The most restrictive condition is the color with the maximum count (z).
 * If we place the z strips of the most frequent color, we have z-1 gaps between them.
 * We can place the other (x + y) strips into these gaps.
 * To ensure no two strips of the most frequent color are adjacent, we need at least
 * (z - 1) strips of other colors to fill the gaps.
 * 
 * Thus, the condition for a valid arrangement is:
 * (x + y) >= (z - 1)
 */

void solve() {
    long long arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    
    // Sort the counts to easily identify the maximum
    sort(arr, arr + 3);
    
    // arr[0] is smallest, arr[1] is middle, arr[2] is largest
    // Condition: sum of two smaller must be at least (largest - 1)
    if (arr[0] + arr[1] >= arr[2] - 1) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
```