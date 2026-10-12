# [Shuffling Parities (SHUFFLIN)](https://www.codechef.com/problems/SHUFFLIN)

- **Difficulty Rating**: 1347
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we define a new array $B$ where $B_i = (A_i + i) \pmod 2$ for $1 \le i \le N$. The goal is to reorder the elements of $A$ such that the sum of the elements in $B$ is maximized. Since $B_i$ can only be 0 or 1, maximizing the sum is equivalent to maximizing the number of indices $i$ where $(A_i + i)$ is odd.

## Intuition & Mathematical Observation
An expression $(A_i + i)$ is odd if and only if $A_i$ and $i$ have **different parities**. 
- If $A_i$ is odd, we want $i$ to be even.
- If $A_i$ is even, we want $i$ to be odd.

Let:
- `odd_val` be the count of odd numbers in $A$.
- `even_val` be the count of even numbers in $A$.
- `odd_pos` be the count of odd indices in $[1, N]$, which is $\lceil N/2 \rceil$.
- `even_pos` be the count of even indices in $[1, N]$, which is $\lfloor N/2 \rfloor$.

To maximize the sum, we should greedily match:
1. As many odd values as possible with even positions: `min(odd_val, even_pos)`.
2. As many even values as possible with odd positions: `min(even_val, odd_pos)`.

The total maximum sum is the sum of these two values.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to count the parity of the elements.
- **Space Complexity**: $O(1)$, as we only store a few integer counters regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * B_i = (A_i + i) % 2
 * We want to maximize the sum of B_i.
 * B_i = 1 if (A_i + i) is odd, which happens if A_i and i have different parities.
 * 
 * Total sum = min(odd_val, even_pos) + min(even_val, odd_pos).
 */

void solve() {
    int N;
    cin >> N;
    
    int odd_val = 0;
    int even_val = 0;
    
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a % 2 != 0) {
            odd_val++;
        } else {
            even_val++;
        }
    }
    
    // Indices are 1 to N.
    // Odd indices: 1, 3, 5... count is ceil(N/2)
    // Even indices: 2, 4, 6... count is floor(N/2)
    int odd_pos = (N + 1) / 2;
    int even_pos = N / 2;
    
    // We want to place odd values in even positions and even values in odd positions
    // to get a 1 in the resulting array B.
    int result = min(odd_val, even_pos) + min(even_val, odd_pos);
    
    cout << result << "\n";
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