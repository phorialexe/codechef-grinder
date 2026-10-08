# [Melt Gold (MELTGOLD)](https://www.codechef.com/problems/MELTGOLD)

- **Difficulty Rating**: 835
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an initial temperature $Y$ and a target melting point $X$. In each minute $i$ (where $i = 1, 2, 3, \dots$), the temperature increases by $i$ degrees. We need to find the minimum number of minutes required for the temperature to reach or exceed $X$.

## Intuition & Mathematical Observation
Let $D = X - Y$ be the total temperature increase required. 
After $n$ minutes, the total increase in temperature is the sum of the first $n$ integers:
$$\text{Total Increase} = 1 + 2 + 3 + \dots + n = \frac{n(n+1)}{2}$$

We need to find the smallest integer $n$ such that:
$$\frac{n(n+1)}{2} \ge D$$

Since the constraints on $X$ and $Y$ are up to $10^5$, the difference $D$ is at most $10^5$. The value of $n$ will be relatively small (approximately $\sqrt{2 \times 10^5} \approx 450$). Therefore, a simple iterative approach that adds $1, 2, 3, \dots$ until the sum reaches or exceeds $D$ is highly efficient and well within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(\sqrt{X-Y})$ per test case. Given the constraints, this is effectively $O(1)$ per test case, or $O(T \cdot \sqrt{D_{max}})$ total.
- **Space Complexity**: $O(1)$, as we only use a few variables to track the current sum and the number of minutes.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial temperature = Y
 * Melting point = X
 * After minute 1: Temp = Y + 1
 * After minute 2: Temp = Y + 1 + 2
 * After minute n: Temp = Y + (1 + 2 + ... + n)
 * Formula for sum of first n integers: n(n+1)/2
 * We need the smallest n such that: Y + n(n+1)/2 >= X
 * Which simplifies to: n(n+1)/2 >= X - Y
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    
    long long diff = X - Y;
    long long current_temp_increase = 0;
    int minutes = 0;
    
    // Increment minutes until the cumulative sum reaches the required difference
    while (current_temp_increase < diff) {
        minutes++;
        current_temp_increase += minutes;
    }
    
    cout << minutes << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
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