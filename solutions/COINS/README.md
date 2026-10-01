# [Bytelandian gold coins (COINS)](https://www.codechef.com/problems/COINS)

- **Difficulty Rating**: 944
- **Solved in**: 1 attempt(s)

## Problem Summary
In Byteland, gold coins have a specific value $n$. You can either sell a coin for $n$ dollars or exchange it for three smaller coins with values $\lfloor n/2 \rfloor$, $\lfloor n/3 \rfloor$, and $\lfloor n/4 \rfloor$. The goal is to maximize the total amount of dollars you can obtain for a given coin of value $n$.

## Intuition & Mathematical Observation
The problem can be modeled using a recursive function $f(n)$:
$$f(n) = \max(n, f(\lfloor n/2 \rfloor) + f(\lfloor n/3 \rfloor) + f(\lfloor n/4 \rfloor))$$

**Key Observations:**
1. **Base Case**: For small values of $n$, specifically $n < 12$, the sum of the parts ($\lfloor n/2 \rfloor + \lfloor n/3 \rfloor + \lfloor n/4 \rfloor$) is always less than or equal to $n$. Thus, for $n < 12$, $f(n) = n$.
2. **Memoization**: Since $n$ can be as large as $10^9$, we cannot use a standard array. However, many subproblems overlap. We use a `std::map` (or a hybrid approach with an array for small values) to store results of previously computed values of $n$ to avoid redundant calculations.
3. **Efficiency**: Because we only branch when $n \ge 12$, the recursion depth is logarithmic, and the number of distinct states visited is relatively small, making memoization highly effective.

## Complexity Analysis
- **Time Complexity**: $O(\log n)$ per test case. While the exact number of states is difficult to bound strictly, the recursive tree is pruned significantly by the base case $n < 12$, leading to very efficient execution.
- **Space Complexity**: $O(K)$, where $K$ is the number of distinct values of $n$ encountered during the recursion that are stored in the map.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For a coin of value n, we have two choices:
 * 1. Sell it for n dollars.
 * 2. Exchange it for coins of value n/2, n/3, and n/4, and sell those.
 * 
 * The recurrence relation is:
 * f(n) = max(n, f(n/2) + f(n/3) + f(n/4))
 */

map<long long, long long> memo;

long long solve(long long n) {
    if (n == 0) return 0;
    // Base case: for n < 12, n/2 + n/3 + n/4 <= n
    if (n < 12) return n; 
    
    // Check memoization table
    if (memo.count(n)) return memo[n];
    
    // Recursive step: choose the maximum of selling or exchanging
    long long res = max(n, solve(n / 2) + solve(n / 3) + solve(n / 4));
    
    return memo[n] = res;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    // Read until EOF as per problem requirements
    while (cin >> n) {
        cout << solve(n) << "\n";
    }
    
    return 0;
}
```