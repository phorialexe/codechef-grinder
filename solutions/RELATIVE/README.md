# [Relativity (RELATIVE)](https://www.codechef.com/problems/RELATIVE)

- **Difficulty Rating**: 872
- **Solved in**: 2 attempt(s)

## Problem Summary
Given the physical formula $v^2 = 2 \cdot g \cdot H$, where $v$ is the velocity, $g$ is the acceleration due to gravity, and $H$ is the height, we are tasked with finding the minimum height $H$ required for a light particle to escape a planet's gravity, given the speed of light $c$ and the acceleration due to gravity $g$. Specifically, we need to calculate $H$ when $v = c$.

## Intuition & Mathematical Observation
The problem provides the equation $v^2 = 2 \cdot g \cdot H$. We are told that the particle must reach the speed of light ($v = c$). By substituting $c$ for $v$, the equation becomes:

$$c^2 = 2 \cdot g \cdot H$$

To isolate $H$, we rearrange the equation:

$$H = \frac{c^2}{2 \cdot g}$$

Since the problem guarantees that $2 \cdot g$ always divides $c^2$ evenly, we can perform integer division to find the exact value of $H$. Given the constraints ($c \le 3000$), $c^2$ will be at most $9,000,000$, which fits comfortably within a standard 32-bit integer, though `long long` is used for safety and best practices.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We are given the equation v^2 = 2 * g * H.
 * We need to find H such that v = c.
 * Substituting v = c:
 * c^2 = 2 * g * H
 * H = c^2 / (2 * g)
 * 
 * Constraints:
 * 1 <= T <= 5000
 * 1 <= g <= 10
 * 1000 <= c <= 3000
 * 2 * g divides c^2, so the result is always an integer.
 */

void solve() {
    long long g, c;
    if (!(cin >> g >> c)) return;
    
    // Calculate H = (c * c) / (2 * g)
    // Using long long to ensure no overflow occurs during c * c
    long long h = (c * c) / (2 * g);
    
    cout << h << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
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