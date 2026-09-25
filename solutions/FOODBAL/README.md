# [Food Balance (FOODBAL)](https://www.codechef.com/problems/FOODBAL)

- **Difficulty Rating**: 215
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine which of two dishes is more "balanced" based on the nutritional content of fat ($F$) and protein ($P$). A dish is considered more balanced if the absolute difference between its fat and protein content is smaller. Given the fat and protein values for two dishes ($F_1, P_1$) and ($F_2, P_2$), we must output:
- "First" if $|F_1 - P_1| < |F_2 - P_2|$
- "Second" if $|F_2 - P_2| < |F_1 - P_1|$
- "Both" if $|F_1 - P_1| = |F_2 - P_2|$

## Intuition & Mathematical Observation
The problem asks us to compare the magnitude of the deviation from equality for two pairs of numbers. 
1. We calculate the absolute difference for the first dish: $D_1 = |F_1 - P_1|$.
2. We calculate the absolute difference for the second dish: $D_2 = |F_2 - P_2|$.
3. By comparing $D_1$ and $D_2$ using standard conditional statements, we can determine which dish has a smaller deviation. Since the constraints are small (1 to 100), the `abs()` function in C++ is perfectly suited for this calculation.

## Complexity Analysis
- **Time Complexity**: $O(1)$. The solution performs a constant number of arithmetic operations and comparisons regardless of the input values.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the input and the calculated differences.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Food Balance
 * The goal is to compare the absolute difference between fat and protein for two dishes.
 * Let D1 = |F1 - P1| and D2 = |F2 - P2|.
 * If D1 < D2, output "First".
 * If D2 < D1, output "Second".
 * If D1 == D2, output "Both".
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int f1, p1, f2, p2;
    
    // Read the four integers representing fat and protein for two dishes
    if (!(cin >> f1 >> p1 >> f2 >> p2)) return 0;

    // Calculate absolute differences
    int diff1 = abs(f1 - p1);
    int diff2 = abs(f2 - p2);

    // Compare and output result
    if (diff1 < diff2) {
        cout << "First" << "\n";
    } else if (diff2 < diff1) {
        cout << "Second" << "\n";
    } else {
        cout << "Both" << "\n";
    }

    return 0;
}
```