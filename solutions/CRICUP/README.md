# [Cup Finals (CRICUP)](https://www.codechef.com/problems/CRICUP)

- **Difficulty Rating**: 716
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a cricket match between two teams with skill levels $X$ and $Y$ can be considered "fair" or "close." Specifically, we are given a threshold $D$. We need to output "YES" if the absolute difference between the skill levels of the two teams is less than or equal to $D$, and "NO" otherwise.

## Intuition & Mathematical Observation
The core of the problem is to compare the gap between two numbers against a given limit. 
1. We are given two skill levels, $X$ and $Y$.
2. The difference between these two levels is calculated as $|X - Y|$.
3. According to the problem constraints, the match is acceptable if $|X - Y| \le D$.
4. Since $X, Y,$ and $D$ are provided as integers, we can simply use the `abs()` function from the `<cmath>` or `<cstdlib>` library to compute the absolute difference and compare it directly with $D$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and a comparison, which takes $O(1)$ time.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of extra space to store the variables $X, Y, D,$ and the difference.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Cup Finals
 * The problem asks us to determine if the absolute difference between two 
 * skill levels X and Y is less than or equal to D.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, d;
        cin >> x >> y >> d;
        
        // Calculate the absolute difference between skill levels
        long long diff = abs(x - y);
        
        // Check if the difference is within the allowed threshold D
        if (diff <= d) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```