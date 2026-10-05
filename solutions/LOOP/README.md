# [Circular Track (LOOP)](https://www.codechef.com/problems/LOOP)

- **Difficulty Rating**: 838
- **Solved in**: 2 attempt(s)

## Problem Summary
You are given a circular track of length $M$ with positions marked from $1$ to $M$. Given two positions $A$ and $B$ on this track, you need to find the minimum distance required to travel between them. Since the track is circular, you can travel either clockwise or counter-clockwise.

## Intuition & Mathematical Observation
On a circular track of length $M$, there are exactly two ways to travel between any two points $A$ and $B$:

1.  **Direct Path**: The absolute difference between the two points, $|A - B|$.
2.  **Wrap-around Path**: The remaining distance of the circle, which is $M - |A - B|$.

To find the minimum distance, we simply calculate both values and take the minimum:
$$\text{Result} = \min(|A - B|, M - |A - B|)$$

**Note on Constraints**: Since $M$ can be as large as $10^9$, using `long long` is a good practice to prevent potential overflow during calculations, although standard `int` would technically suffice for these specific operations.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * On a circular track of length M, there are two paths between any two points A and B.
 * Path 1: Direct distance = abs(A - B)
 * Path 2: The "other way" around = M - abs(A - B)
 * The minimum distance is the minimum of these two values.
 */

void solve() {
    long long A, B, M;
    if (!(cin >> A >> B >> M)) return;
    
    // Calculate the absolute difference between the two points
    long long diff = abs(A - B);
    
    // The minimum distance is the smaller of the direct path or the wrap-around path
    long long min_dist = min(diff, M - diff);
    
    cout << min_dist << "\n";
}

int main() {
    // Fast I/O for performance
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