# [Bucket and Water Flow (WATERFLOW)](https://www.codechef.com/problems/WATERFLOW)

- **Difficulty Rating**: 483
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a bucket with an initial amount of water $W$ and a maximum capacity $X$. Water is poured into the bucket at a rate of $Y$ units per hour for a duration of $Z$ hours. We need to determine if the bucket overflows, is exactly filled, or remains unfilled after the given time.

## Intuition & Mathematical Observation
The total amount of water in the bucket after $Z$ hours is calculated by adding the initial amount $W$ to the total inflow, which is the product of the rate $Y$ and the time $Z$.

Let $TotalWater = W + (Y \times Z)$.

We compare $TotalWater$ with the capacity $X$:
1. If $TotalWater > X$: The bucket **overflows**.
2. If $TotalWater == X$: The bucket is **filled** exactly.
3. If $TotalWater < X$: The bucket is **unfilled**.

Since the constraints for $W, X, Y, Z$ are up to $1000$, the maximum possible value for $TotalWater$ is $1,000 + (1,000 \times 1,000) = 1,001,000$. This fits well within a standard 32-bit integer, though `long long` is used in the implementation for robustness.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated total.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial water = W
 * Capacity = X
 * Inflow rate = Y
 * Time = Z
 * Total water after Z hours = W + (Y * Z)
 * 
 * Comparison:
 * If (W + Y * Z) > X: overflow
 * If (W + Y * Z) == X: filled
 * If (W + Y * Z) < X: unfilled
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long W, X, Y, Z;
        cin >> W >> X >> Y >> Z;
        
        long long total_water = W + (Y * Z);
        
        if (total_water > X) {
            cout << "overflow" << "\n";
        } else if (total_water == X) {
            cout << "filled" << "\n";
        } else {
            cout << "unfilled" << "\n";
        }
    }
    
    return 0;
}
```