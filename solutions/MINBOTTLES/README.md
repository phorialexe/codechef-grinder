# [Minimum Bottles (MINBOTTLES)](https://www.codechef.com/problems/MINBOTTLES)

- **Difficulty Rating**: 656
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ bottles, each with a capacity of $X$ liters. You are also given the current amount of water in each of the $N$ bottles. Since you can transfer water freely between bottles without any spillage, the goal is to determine the minimum number of bottles required to store the total volume of water currently present across all $N$ bottles.

## Intuition & Mathematical Observation
The problem asks us to consolidate the total volume of water into the fewest number of containers possible. 

1. **Calculate Total Volume**: First, we sum the water currently in all $N$ bottles to get a total volume $S = \sum_{i=1}^{N} A_i$.
2. **Determine Capacity**: Each bottle has a fixed capacity $X$.
3. **Calculate Minimum Bottles**: We need to find the smallest integer $k$ such that $k \times X \geq S$. This is mathematically equivalent to the ceiling function: $k = \lceil \frac{S}{X} \rceil$.
4. **Integer Arithmetic**: In C++, performing floating-point division can lead to precision issues. We can implement the ceiling division for integers using the formula:
   $$\text{result} = \frac{S + X - 1}{X}$$
   This formula correctly computes the ceiling of the division for positive integers.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of bottles. We iterate through the input array exactly once to calculate the sum.
- **Space Complexity**: $O(1)$, as we only store the running sum and a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N bottles, each with capacity X.
 * We have a total volume of water S = sum(A_i).
 * Since we can transfer water freely between bottles without spillage,
 * we want to pack the total volume S into the minimum number of bottles.
 * 
 * Each bottle can hold at most X liters.
 * If we have S liters of water, the number of bottles required is the smallest 
 * integer k such that k * X >= S.
 * This is equivalent to ceil(S / X).
 * Using integer arithmetic, ceil(S / X) can be calculated as (S + X - 1) / X.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    
    long long total_water = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        total_water += a;
    }
    
    // We need to find the minimum number of bottles k such that k * X >= total_water.
    // k = ceil(total_water / X)
    // Using integer division: (total_water + X - 1) / X
    long long min_bottles = (total_water + X - 1) / X;
    
    cout << min_bottles << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}
```