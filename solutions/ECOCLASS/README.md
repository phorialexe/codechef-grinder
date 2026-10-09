# [Economics Class (ECOCLASS)](https://www.codechef.com/problems/ECOCLASS)

- **Difficulty Rating**: 787
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the number of "equilibrium" points between two lists of integers, $S$ (supply) and $D$ (demand), both of length $N$. An equilibrium point occurs at index $i$ if the supply value at that index is exactly equal to the demand value at the same index ($S[i] = D[i]$). We need to output the total count of such indices for each test case.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. Since we are given two arrays of the same length $N$, we simply need to iterate through the arrays from index $0$ to $N-1$ and check the condition $S[i] == D[i]$. 

- We store the supply values in one array (or vector) and the demand values in another.
- We maintain a counter variable, `equilibrium_count`, initialized to zero.
- For every index $i$, if $S[i]$ equals $D[i]$, we increment the counter.
- After checking all indices, the counter holds the total number of equilibrium points.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of elements in the arrays. We perform a single pass through the arrays for each test case. Given $N \le 100$ and $T \le 10$, this is well within the time limits.
- **Space Complexity**: $O(N)$, as we store the supply and demand values in vectors of size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Economics Class
 * The goal is to count the number of indices i such that S[i] == D[i].
 * Given constraints: N <= 100, T <= 10.
 * Time Complexity: O(T * N)
 * Space Complexity: O(N)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> s(n);
        vector<int> d(n);
        
        // Read supply values
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        // Read demand values
        for (int i = 0; i < n; ++i) {
            cin >> d[i];
        }
        
        int equilibrium_count = 0;
        // Compare values at each index
        for (int i = 0; i < n; ++i) {
            if (s[i] == d[i]) {
                equilibrium_count++;
            }
        }
        
        cout << equilibrium_count << "\n";
    }
    
    return 0;
}
```