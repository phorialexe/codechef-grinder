# [Fill Candies (FILLCANDIES)](https://www.codechef.com/problems/FILLCANDIES)

- **Difficulty Rating**: 681
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ candies, and you have bags that contain $K$ pockets each. Each pocket can hold exactly $M$ candies. You need to determine the minimum number of bags required to store all $N$ candies.

## Intuition & Mathematical Observation
1. **Calculate Capacity per Bag**: Since each bag has $K$ pockets and each pocket holds $M$ candies, the total capacity of a single bag is $K \times M$.
2. **Determine Bags Needed**: To store $N$ candies, we need to divide $N$ by the capacity per bag. If there is any remainder, we need an additional bag. This is equivalent to the ceiling function: $\lceil \frac{N}{K \times M} \rceil$.
3. **Integer Arithmetic Trick**: In programming, performing ceiling division $\lceil \frac{a}{b} \rceil$ using integers can be done efficiently without floating-point numbers using the formula:
   $$\text{result} = \frac{a + b - 1}{b}$$
   This avoids precision issues and is standard practice in competitive programming.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each bag has K pockets.
 * Each pocket can hold M candies.
 * Therefore, one bag can hold a total of (K * M) candies.
 * To find the minimum number of bags needed for N candies, we need to calculate:
 * ceil(N / (K * M))
 * 
 * Using integer arithmetic, ceil(a / b) can be calculated as (a + b - 1) / b.
 */

int main() {
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k, m;
        cin >> n >> k >> m;

        // Capacity of one bag
        long long capacity_per_bag = k * m;

        // Calculate minimum bags needed using integer division ceiling formula
        // Result = (n + capacity_per_bag - 1) / capacity_per_bag
        long long bags_needed = (n + capacity_per_bag - 1) / capacity_per_bag;

        cout << bags_needed << "\n";
    }

    return 0;
}
```