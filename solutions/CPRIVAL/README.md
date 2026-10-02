# [Rivalry (CPRIVAL)](https://www.codechef.com/problems/CPRIVAL)

- **Difficulty Rating**: 501
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the winner of a rating rivalry between two individuals, "Dominater" and "Everule." We are given their initial ratings ($R_1$ and $R_2$) and the rating changes they experienced ($D_1$ and $D_2$). We need to calculate their final ratings by adding the changes to the initial values and output the name of the person who ends up with the higher final rating.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic comparison. 
1. Calculate the final rating for Dominater: $Final_{Dominater} = R_1 + D_1$.
2. Calculate the final rating for Everule: $Final_{Everule} = R_2 + D_2$.
3. Compare the two results:
   - If $Final_{Dominater} > Final_{Everule}$, Dominater is the winner.
   - Otherwise, Everule is the winner.

Since the input values are within standard integer ranges, `long long` is used to ensure no overflow occurs, though standard `int` would also suffice given the typical constraints for this difficulty level.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and comparisons, regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store the four input variables and two result variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Rivalry
 * The problem asks us to compare the final ratings of two individuals, 
 * Dominater and Everule, after their initial ratings are modified by 
 * given rating changes.
 * 
 * Final Rating of Dominater = R1 + D1
 * Final Rating of Everule = R2 + D2
 * 
 * We compare these two values and print the name of the person with the higher rating.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long R1, R2;
    long long D1, D2;

    // Reading input
    if (!(cin >> R1 >> R2)) return 0;
    if (!(cin >> D1 >> D2)) return 0;

    // Calculating final ratings
    long long final_dominater = R1 + D1;
    long long final_everule = R2 + D2;

    // Comparing and outputting the result
    if (final_dominater > final_everule) {
        cout << "Dominater" << "\n";
    } else {
        cout << "Everule" << "\n";
    }

    return 0;
}
```