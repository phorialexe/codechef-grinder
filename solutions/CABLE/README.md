# [Volume Comparison (CABLE)](https://www.codechef.com/problems/CABLE)

- **Difficulty Rating**: 318
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to compare the volume of a cuboid with the volume of a cube. Given the dimensions of a cuboid ($A, B, C$) and the side length of a cube ($X$), we need to determine which volume is larger or if they are equal.
- Volume of cuboid = $A \times B \times C$
- Volume of cube = $X \times X \times X$

## Intuition & Mathematical Observation
The problem is a direct application of volume calculation formulas. Since the constraints for $A, B, C,$ and $X$ are small (up to 10), the resulting volumes will not exceed $1000$. Even if the constraints were larger, using `long long` in C++ ensures that we avoid potential integer overflow issues during multiplication.

The logic follows a simple conditional structure:
1. Calculate `vol_cuboid = A * B * C`.
2. Calculate `vol_cube = X * X * X`.
3. Compare the two values:
   - If `vol_cuboid > vol_cube`, output "Cuboid".
   - If `vol_cube > vol_cuboid`, output "Cube".
   - Otherwise, output "Equal".

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and comparisons regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the four integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Volume Comparison
 * The volume of a cuboid is A * B * C.
 * The volume of a cube is X * X * X.
 * We compare these two values and output the result.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B, C, X;
    
    // Read the dimensions
    if (cin >> A >> B >> C >> X) {
        long long vol_cuboid = A * B * C;
        long long vol_cube = X * X * X;

        // Compare volumes and print the result
        if (vol_cuboid > vol_cube) {
            cout << "Cuboid" << "\n";
        } else if (vol_cube > vol_cuboid) {
            cout << "Cube" << "\n";
        } else {
            cout << "Equal" << "\n";
        }
    }

    return 0;
}
```