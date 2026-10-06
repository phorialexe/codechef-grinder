# [Playing with Toys (TOYS)](https://www.codechef.com/problems/TOYS)

- **Difficulty Rating**: 206
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef starts with $N$ toys. Each day, he plays with one toy, which results in that toy breaking. We need to determine how many toys remain after $M$ days. If the number of days $M$ exceeds or equals the number of toys $N$, all toys will be broken, leaving 0. Otherwise, the remaining toys will be $N - M$.

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic task. Since one toy is consumed per day:
1. If $M \ge N$: Chef runs out of toys before or exactly on the day he finishes the last one. The result is $0$.
2. If $M < N$: Chef has enough toys to last through all $M$ days, leaving $N - M$ toys remaining.

This can be elegantly expressed using the formula: $\max(0, N - M)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$ — No additional data structures are used; only a few integer variables are stored.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

/**
 * Problem Analysis:
 * Chef starts with N toys.
 * Each day, if he has at least one toy, he plays with one and breaks it.
 * This means he loses 1 toy per day, provided he has toys available.
 * 
 * After M days:
 * - If M >= N, he will break all N toys and be left with 0.
 * - If M < N, he will break M toys and be left with N - M.
 * 
 * The logic is simply: max(0, N - M).
 */

int main() {
    // Optimize I/O operations for faster execution
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    // Read N (total toys) and M (days passed)
    if (std::cin >> n >> m) {
        // If days passed are greater than or equal to toys, 0 remain.
        // Otherwise, subtract days from total toys.
        if (m >= n) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << (n - m) << std::endl;
        }
    }
    
    return 0;
}
```