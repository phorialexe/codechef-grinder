# [Chocolate Distribution (CHOCDISTRIB)](https://www.codechef.com/problems/CHOCDISTRIB)

- **Difficulty Rating**: 595
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ chocolates, we need to distribute them among children such that each child receives either 1 or 2 chocolates. We are tasked with finding the **minimum** and **maximum** number of children that can receive these chocolates under these constraints.

## Intuition & Mathematical Observation

### 1. Finding the Minimum Number of Children
To minimize the number of children, we want to give as many children as possible the maximum allowed amount (2 chocolates).
*   If $N$ is even, we can give 2 chocolates to every child. The number of children is $N / 2$.
*   If $N$ is odd, we give 2 chocolates to $(N-1)/2$ children, and the remaining 1 chocolate goes to one additional child.
*   Mathematically, this is equivalent to $\lceil N / 2 \rceil$. Using integer division, this can be calculated as `(N + 1) / 2`.

### 2. Finding the Maximum Number of Children
To maximize the number of children, we want to give as few chocolates as possible to each child. Since the minimum amount a child can receive is 1 chocolate, we give exactly 1 chocolate to every child.
*   The maximum number of children is simply $N$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N chocolates. Each child receives either 1 or 2 chocolates.
 * 
 * To minimize the number of children:
 * We should give as many children as possible 2 chocolates.
 * If N is even, min children = N / 2.
 * If N is odd, we give 2 chocolates to (N-1)/2 children and 1 chocolate to 1 child.
 * Total min children = (N / 2) + (N % 2).
 * This is equivalent to ceil(N / 2.0) or (N + 1) / 2.
 * 
 * To maximize the number of children:
 * We should give as many children as possible 1 chocolate.
 * Since every child must receive at least 1 chocolate, the maximum number of children
 * is achieved by giving exactly 1 chocolate to every child.
 * Total max children = N.
 */

void solve() {
    long long N;
    cin >> N;
    
    // Minimum children: ceil(N / 2)
    // Using integer arithmetic: (N + 1) / 2
    long long min_children = (N + 1) / 2;
    
    // Maximum children: N (giving 1 chocolate to each)
    long long max_children = N;
    
    cout << min_children << " " << max_children << "\n";
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