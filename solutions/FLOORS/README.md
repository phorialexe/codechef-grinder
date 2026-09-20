# [Too many Floors (FLOORS)](https://www.codechef.com/problems/FLOORS)

- **Difficulty Rating**: 717
- **Solved in**: 1 attempt(s)

## Problem Summary
In a building, each floor contains exactly 10 rooms. Specifically, rooms 1–10 are on the 1st floor, 11–20 are on the 2nd floor, and so on. Given two room numbers $X$ and $Y$, calculate the minimum number of floors one needs to travel to get from the floor containing room $X$ to the floor containing room $Y$.

## Intuition & Mathematical Observation
Since each floor holds 10 rooms, we can determine the floor number of any room $N$ using the formula:
$$\text{Floor}(N) = \lceil N / 10 \rceil$$

In integer arithmetic, this is equivalent to:
$$\text{Floor}(N) = (N + 9) / 10$$

By applying this formula to both room $X$ and room $Y$, we obtain their respective floor numbers. The number of floors to travel is simply the absolute difference between these two values:
$$\text{Distance} = |\text{Floor}(X) - \text{Floor}(Y)|$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each floor has 10 rooms.
 * Floor 1: 1-10
 * Floor 2: 11-20
 * ...
 * Floor i: 10*(i-1) + 1 to 10*i
 * 
 * To find the floor number for a room X:
 * Floor(X) = ceil(X / 10.0)
 * Using integer arithmetic, this is (X + 9) / 10.
 * 
 * The number of floors to travel is the absolute difference between the floor numbers.
 */

void solve() {
    int x, y;
    cin >> x >> y;
    
    // Calculate floor for room X
    int floorX = (x + 9) / 10;
    
    // Calculate floor for room Y
    int floorY = (y + 9) / 10;
    
    // The number of floors to travel is the absolute difference
    int result = abs(floorX - floorY);
    
    cout << result << "\n";
}

int main() {
    // Fast I/O
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