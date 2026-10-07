# [Mask Policy (MASKPOL)](https://www.codechef.com/problems/MASKPOL)

- **Difficulty Rating**: 1064
- **Solved in**: 1 attempt(s)

## Problem Summary
In a population of $N$ people, $A$ people are infected with a virus. To prevent the virus from spreading, any interaction between an infected person and an uninfected person must be avoided. The mayor decides to mandate masks for a specific group of people such that no interaction between an infected and an uninfected person occurs without a mask. The goal is to find the **minimum** number of people who must wear a mask to satisfy this condition.

## Intuition & Mathematical Observation
To prevent the spread of the virus, we must ensure that there is no "unprotected" interaction between an infected person and a healthy person. 

There are two primary strategies to achieve this:
1. **Mask all infected people ($A$):** If every infected person wears a mask, they cannot transmit the virus to any healthy person, regardless of whether the healthy people are wearing masks or not.
2. **Mask all healthy people ($N - A$):** If every healthy person wears a mask, they are protected from the virus, regardless of whether the infected people are wearing masks or not.

Since the mayor wants to minimize the number of people wearing masks, we simply compare the size of these two groups and choose the smaller one:
$$\text{Result} = \min(A, N - A)$$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time calculation.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N people in total, A of whom are infected.
 * The virus spreads if an infected person and an uninfected person interact 
 * without masks.
 * 
 * To stop the spread, we need to ensure that no interaction between an 
 * infected person and an uninfected person occurs without a mask.
 * 
 * If we mask all A infected people, the virus cannot spread.
 * If we mask all (N - A) uninfected people, the virus cannot spread.
 * 
 * The mayor wants the minimum number of people to wear a mask.
 * Therefore, we should choose the smaller group: min(A, N - A).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, a;
        cin >> n >> a;
        
        // The minimum number of people to mask is the smaller of the two groups:
        // the infected group (A) or the healthy group (N - A).
        int result = min(a, n - a);
        
        cout << result << "\n";
    }
    
    return 0;
}
```