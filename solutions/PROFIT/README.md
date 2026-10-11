# [Profits (PROFIT)](https://www.codechef.com/problems/PROFIT)

- **Difficulty Rating**: 607
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ customers, where the $i$-th customer pays $i$ units. The cost to produce one lemonade is $X$. Chef wants to maximize their total profit. Since Chef can choose which customers to serve, they should only serve customers who provide a positive profit (i.e., customers where $i > X$). If the cost $X$ is greater than or equal to the highest-paying customer $N$, the maximum profit is 0.

## Intuition & Mathematical Observation
To maximize profit, we only accept customers where the payment $i$ is strictly greater than the cost $X$. 

1. **Identify the range**: We serve customers from $i = X + 1$ to $N$.
2. **Calculate individual profit**: For a customer $i$, the profit is $(i - X)$.
3. **Summation**: The total profit is the sum of $(i - X)$ for all $i$ from $X+1$ to $N$.
   - Let $k = i - X$.
   - When $i = X + 1$, $k = 1$.
   - When $i = N$, $k = N - X$.
   - The total profit becomes the sum of the first $(N - X)$ natural numbers: $\sum_{k=1}^{N-X} k$.
4. **Formula**: Using the arithmetic series sum formula $\frac{n(n+1)}{2}$, where $n = N - X$:
   $$\text{Profit} = \frac{(N - X)(N - X + 1)}{2}$$
5. **Edge Case**: If $X \ge N$, no customer yields a positive profit, so the result is $0$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation is performed using a constant-time mathematical formula.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N customers. The i-th customer pays i.
 * Cost to make one lemonade is X.
 * Profit from the i-th customer is (i - X).
 * To maximize total profit, Chef should accept all customers for whom (i - X) > 0.
 * That is, accept all customers where i > X.
 * 
 * If i <= X, the profit is <= 0, so we should reject those customers.
 * 
 * Total Profit = Sum_{i=X+1}^{N} (i - X)
 * If X >= N, no customer provides a positive profit, so max profit is 0.
 */

void solve() {
    long long N, X;
    cin >> N >> X;

    // If the cost X is greater than or equal to the highest paying customer N,
    // no customer can provide a positive profit.
    if (X >= N) {
        cout << 0 << "\n";
        return;
    }

    // We accept customers from X + 1 to N.
    // Profit = sum_{i=X+1}^{N} (i - X)
    // Let k = i - X. When i = X+1, k = 1. When i = N, k = N - X.
    // Profit = sum_{k=1}^{N-X} k
    // This is an arithmetic series: (count * (first + last)) / 2
    // count = N - X
    // first = 1
    // last = N - X
    
    long long count = N - X;
    long long profit = (count * (1 + count)) / 2;
    
    cout << profit << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```