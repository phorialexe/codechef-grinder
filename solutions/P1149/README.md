# [Approximate Answer (P1149)](https://www.codechef.com/problems/P1149)

- **Difficulty Rating**: 291
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $X$, $Y$, and $K$, determine if the absolute difference between $X$ and $Y$ is less than or equal to $K$. In other words, check if $|X - Y| \le K$.

## Intuition & Mathematical Observation
The problem asks for a direct comparison of the distance between two points on a number line against a threshold $K$. 
1. The absolute difference $|X - Y|$ represents the distance between $X$ and $Y$.
2. We can compute this using the `abs()` function in C++.
3. Since the constraints are very small ($1 \le X, Y, K \le 20$), standard integer types are more than sufficient to store the values and perform the comparison.
4. If the calculated difference is less than or equal to $K$, output "Yes"; otherwise, output "No".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single subtraction and a comparison.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space to store the input variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Approximate Answer
 * The problem asks to check if |X - Y| <= K.
 * Given constraints are small (1 <= X, Y, K <= 20), so standard integer types are sufficient.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y, K;
    if (cin >> X >> Y >> K) {
        // Calculate absolute difference
        long long diff = abs(X - Y);
        
        // Check condition |X - Y| <= K
        if (diff <= K) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```