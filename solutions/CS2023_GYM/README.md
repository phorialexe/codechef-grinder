# [Gymkhana Election IIIT-A (CS2023_GYM)](https://www.codechef.com/problems/CS2023_GYM)

- **Difficulty Rating**: 629
- **Solved in**: 1 attempt(s)

## Problem Summary
In an election with $N$ nominees and $M$ total votes, Om wants to win with a "strict majority." This means that if Om receives $X$ votes, every other nominee must receive strictly fewer than $X$ votes. We need to find the minimum number of votes $X$ Om must secure to guarantee a win, regardless of how the remaining $(M - X)$ votes are distributed among the other $(N - 1)$ nominees.

## Intuition & Mathematical Observation
To guarantee a win, Om must ensure that even in the worst-case scenario—where all remaining votes are concentrated on a single opponent—that opponent still has fewer votes than Om.

1. Let $X$ be the number of votes Om receives.
2. The remaining votes are $M - X$.
3. In the worst-case scenario, one opponent receives all the remaining votes: $M - X$.
4. For Om to win, this opponent must have strictly fewer votes than Om:
   $$M - X < X$$
5. Rearranging the inequality:
   $$M < 2X$$
   $$X > \frac{M}{2}$$
6. Since $X$ must be an integer, the minimum value for $X$ is $\lfloor \frac{M}{2} \rfloor + 1$.

**Example Check:**
- For $N=5, M=12$: $X > 12/2 \implies X > 6$. The minimum $X$ is $7$.
- For $N=2, M=5$: $X > 5/2 \implies X > 2.5$. The minimum $X$ is $3$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic calculation. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To guarantee a strict majority, Om needs more votes than any other 
 * single person could possibly accumulate. In the worst case, all 
 * remaining (M - X) votes are given to a single opponent.
 * Therefore, we need (M - X) < X, which simplifies to M < 2X, 
 * or X > M / 2. The smallest integer X satisfying this is (M / 2) + 1.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        
        // The minimum votes required is floor(M / 2) + 1
        cout << (m / 2) + 1 << "\n";
    }
    return 0;
}
```