# [Painting Walls (PAINTCHRIS)](https://www.codechef.com/problems/PAINTCHRIS)

- **Difficulty Rating**: 567
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given the dimensions of a wall ($X \times Y$) and a total budget ($Z$). It costs 2 rupees to paint 1 square meter of the wall. Your task is to determine the maximum number of walls that can be painted completely given the budget $Z$.

## Intuition & Mathematical Observation
1. **Calculate Area**: The area of a single wall is given by $Area = X \times Y$.
2. **Calculate Cost**: Since the cost is 2 rupees per square meter, the cost to paint one wall is $Cost_{wall} = (X \times Y) \times 2$.
3. **Calculate Capacity**: To find how many walls can be painted with budget $Z$, we perform integer division: $MaxWalls = \lfloor \frac{Z}{Cost_{wall}} \rfloor$.
4. **Constraints**: With $X, Y \le 10$ and $Z \le 100$, the values fit comfortably within standard integer types. Integer division in C++ naturally performs the floor operation required.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Each wall has dimensions X * Y.
 * 2. Area of one wall = X * Y (m^2).
 * 3. Cost per m^2 = 2 rupees.
 * 4. Cost to paint one wall = (X * Y) * 2.
 * 5. Total budget = Z.
 * 6. Maximum number of walls = floor(Z / cost_per_wall).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, y, z;
        cin >> x >> y >> z;
        
        // Calculate area of one wall
        long long area = x * y;
        
        // Calculate cost to paint one wall
        long long cost_per_wall = area * 2;
        
        // Calculate how many walls can be painted completely
        // Integer division handles the floor operation automatically
        if (cost_per_wall == 0) {
            cout << 0 << "\n";
        } else {
            long long max_walls = z / cost_per_wall;
            cout << max_walls << "\n";
        }
    }
    
    return 0;
}
```