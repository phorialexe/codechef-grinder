# [Greedy puppy (GDOG)](https://www.codechef.com/problems/GDOG)

- **Difficulty Rating**: 1306
- **Solved in**: 1 attempt(s)

## Problem Summary
Tuzik has $N$ coins and wants to distribute them among $i$ people, where $1 \le i \le K$. When he distributes the coins equally among $i$ people, he keeps the remainder for himself. The goal is to choose an integer $i$ in the range $[1, K]$ such that the remainder $N \pmod i$ is maximized.

## Intuition & Mathematical Observation
The problem asks us to find $\max(N \pmod i)$ for all $1 \le i \le K$. 

By definition, the remainder $N \pmod i$ is the amount left over after dividing $N$ by $i$. Since the constraints are $N, K \le 10^5$ and $T \le 50$, a brute-force approach checking every possible value of $i$ from $1$ to $K$ is computationally efficient. 

The total number of operations per test case is $K$. With $T$ test cases, the total operations are $T \times K \approx 5 \times 10^6$, which comfortably fits within the standard 1-second time limit (usually allowing for $\sim 10^8$ operations).

## Complexity Analysis
- **Time Complexity**: $O(T \times K)$, where $T$ is the number of test cases and $K$ is the maximum number of people. Given the constraints, this is well within the limits.
- **Space Complexity**: $O(1)$, as we only use a few variables to track the maximum remainder and the current loop index.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tuzik has N coins and can choose between 1 and K people.
 * When he chooses 'i' people (where 1 <= i <= K), the number of coins 
 * left for Tuzik is N % i.
 * We need to find the maximum value of (N % i) for all 1 <= i <= K.
 */

void solve() {
    long long N, K;
    if (!(cin >> N >> K)) return;

    long long max_coins = 0;
    
    // Iterate through all possible number of people from 1 to K
    // and find the maximum remainder N % i.
    for (long long i = 1; i <= K; ++i) {
        long long remainder = N % i;
        if (remainder > max_coins) {
            max_coins = remainder;
        }
    }
    
    cout << max_coins << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
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