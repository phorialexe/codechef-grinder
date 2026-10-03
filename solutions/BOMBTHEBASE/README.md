# [Bomb the base (BOMBTHEBASE)](https://www.codechef.com/problems/BOMBTHEBASE)

- **Difficulty Rating**: 982
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ houses arranged in a line, each with a specific defense strength $A_i$. A bomb with strength $X$ is dropped. The rule states that if a house $i$ has a defense strength $A_i < X$, it is destroyed. Furthermore, if house $i$ is destroyed, all houses $j$ such that $1 \le j \le i$ are also destroyed. We need to find the total number of houses destroyed given the bomb's strength $X$.

## Intuition & Mathematical Observation
The problem states that if house $i$ is destroyed, all houses to its left are also destroyed. This implies that if we find the **rightmost** house $i$ that satisfies the condition $A_i < X$, then all houses from $1$ to $i$ will be destroyed. 

Since we want to maximize the number of destroyed houses, we simply need to track the largest index $i$ where the condition $A_i < X$ holds true. If no house satisfies $A_i < X$, then zero houses are destroyed.

**Key logic:**
- Iterate through the array of house strengths.
- Keep track of the index of the last house that satisfies $A_i < X$.
- Since the input is processed sequentially, the last index updated will naturally be the rightmost one.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of houses. We iterate through the list of houses exactly once.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the current index and the maximum index found so far, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N houses with defense strengths A_1, A_2, ..., A_N.
 * A bomb with strength X destroys house i if A_i < X.
 * If house i is destroyed, all houses j where 1 <= j <= i are destroyed.
 * To maximize the number of destroyed houses, we need to find the largest index i
 * such that A_i < X. If such an index exists, the number of destroyed houses is i.
 * If no such house exists, the answer is 0.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    
    int max_index = 0;
    for (int i = 1; i <= N; ++i) {
        long long A;
        cin >> A;
        // If the current house can be destroyed by the bomb,
        // it is a candidate for the rightmost house destroyed.
        if (A < X) {
            max_index = i;
        }
    }
    
    cout << max_index << "\n";
}

int main() {
    // Fast I/O setup
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