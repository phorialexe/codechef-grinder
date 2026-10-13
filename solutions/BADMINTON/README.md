# [Badminton Serves (BADMINTON)](https://www.codechef.com/problems/BADMINTON)

- **Difficulty Rating**: 869
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game of badminton, Chef serves from the right side of the court whenever his current score is an even number. Given Chef's current score $P$, we need to determine how many times Chef has served from the right side since the beginning of the game (starting from score 0).

## Intuition & Mathematical Observation
Chef serves from the right side when his score is $0, 2, 4, 6, \dots$. 
This forms an arithmetic progression where the $n$-th term is given by $2k$ for $k = 0, 1, 2, \dots$.

We are looking for the number of even integers $x$ such that $0 \le x \le P$.
- If $P=0$, the sequence is $\{0\}$, count = 1.
- If $P=1$, the sequence is $\{0\}$, count = 1.
- If $P=2$, the sequence is $\{0, 2\}$, count = 2.
- If $P=3$, the sequence is $\{0, 2\}$, count = 2.

The pattern shows that the number of times Chef serves from the right is equivalent to the number of even integers in the range $[0, P]$. Mathematically, this is calculated as:
$$\text{Count} = \lfloor P/2 \rfloor + 1$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves a single division and addition.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts serving from the right side.
 * He serves from the right side whenever his current score is even.
 * The sequence of scores when he serves from the right is: 0, 2, 4, 6, ..., up to P.
 * This is an arithmetic progression: 0, 2, 4, ..., 2k, where 2k <= P.
 * We need to find the number of terms in this sequence.
 * The terms are 2*0, 2*1, 2*2, ..., 2*k.
 * The number of terms is k + 1.
 * Since 2k <= P, k <= P/2.
 * The number of terms is floor(P/2) + 1.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p;
        cin >> p;
        
        // The number of times Chef serves from the right is floor(p / 2) + 1
        long long result = (p / 2) + 1;
        cout << result << "\n";
    }

    return 0;
}
```