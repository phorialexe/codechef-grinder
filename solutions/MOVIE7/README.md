# [Movie (MOVIE7)](https://www.codechef.com/problems/MOVIE7)

- **Difficulty Rating**: 576
- **Solved in**: 1 attempt(s)

## Problem Summary
You need to purchase $N$ movie tickets and $M$ buckets of popcorn. You are given the individual prices for a ticket ($A$) and a bucket of popcorn ($B$), as well as the price of a combo ($C$) which includes one ticket and one bucket of popcorn. The goal is to calculate the minimum total cost to acquire exactly $N$ tickets and $M$ buckets of popcorn.

## Intuition & Mathematical Observation
The problem asks for the most cost-effective way to fulfill the requirements. We are given that a combo costs $C$. 

1. **Greedy Strategy**: Since a combo consists of one ticket and one popcorn, we should prioritize buying combos as long as we need both items. The maximum number of combos we can purchase is limited by the smaller of the two quantities, $k = \min(N, M)$.
2. **Remaining Items**: After purchasing $k$ combos, we will have either zero tickets or zero popcorn buckets remaining. 
   - If $N > M$, we still need $(N - M)$ tickets at price $A$.
   - If $M > N$, we still need $(M - N)$ buckets of popcorn at price $B$.
3. **Formula**: The total cost can be expressed as:
   $$\text{Total Cost} = (k \times C) + ((N - k) \times A) + ((M - k) \times B)$$
   This formula works universally because if $N=k$, the term $(N-k)$ becomes 0, and similarly for $M$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to buy N tickets and M buckets of popcorn.
 * Prices:
 * - Ticket: A
 * - Popcorn: B
 * - Combo (1 Ticket + 1 Popcorn): C
 * 
 * Since C < A + B, it is always optimal to use as many combos as possible.
 * The maximum number of combos we can form is min(N, M).
 * Let k = min(N, M).
 * We buy k combos at price C.
 * Remaining items:
 * - If N > M, we have (N - M) tickets left to buy at price A.
 * - If M > N, we have (M - N) buckets of popcorn left to buy at price B.
 * - If N == M, we have 0 items left.
 * 
 * Total cost = (k * C) + ((N - k) * A) + ((M - k) * B)
 */

void solve() {
    long long N, M, A, B, C;
    if (!(cin >> N >> M >> A >> B >> C)) return;

    long long k = min(N, M);
    long long total_cost = (k * C) + ((N - k) * A) + ((M - k) * B);
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```