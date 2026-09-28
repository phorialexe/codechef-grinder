# [The Squid Game (SQUIDRULE)](https://www.codechef.com/problems/SQUIDRULE)

- **Difficulty Rating**: 970
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game with $N$ players, each player $i$ has an associated value $A_i$. If a player is eliminated, their value $A_i$ is added to the prize pool. If we choose a specific player $k$ to be the winner, all other players are eliminated. The goal is to choose the winner such that the total prize money (the sum of all $A_i$ except $A_k$) is maximized.

## Intuition & Mathematical Observation
Let $S$ be the total sum of all values in the array $A$, where $S = \sum_{i=1}^{N} A_i$.
If we choose player $k$ as the winner, the prize money they receive is:
$$\text{Prize}_k = S - A_k$$

To maximize the prize money, we need to subtract the smallest possible value from the total sum. Therefore, we should choose the player with the minimum value $A_i$ to be the winner. The maximum prize is simply:
$$\text{Max Prize} = S - \min(A_1, A_2, \dots, A_N)$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to calculate the total sum and find the minimum element.
- **Space Complexity**: $O(1)$, as we only store a few variables (`sum`, `min_val`, `a`) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N players. When player i is eliminated, A[i] is added to the pool.
 * If we choose player k to be the winner, all players except player k are eliminated.
 * The total prize money won by player k is the sum of A[i] for all i != k.
 * 
 * Let S be the sum of all elements in array A.
 * The prize money for winner k is S - A[k].
 * To maximize this value, we need to minimize A[k].
 * Therefore, the maximum prize is S - min(A).
 */

void solve() {
    int N;
    cin >> N;
    
    long long sum = 0;
    int min_val = 10001; // Since A_i <= 10^4, 10001 is a safe initial value
    
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        sum += a;
        if (a < min_val) {
            min_val = a;
        }
    }
    
    // The winner gets the sum of all A_i except the one corresponding to the winner.
    // To maximize the prize, we pick the player with the smallest A_i to be the winner.
    cout << (sum - min_val) << "\n";
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}
```