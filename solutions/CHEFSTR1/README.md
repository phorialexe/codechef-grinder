# [Chef and Strings (CHEFSTR1)](https://www.codechef.com/problems/CHEFSTR1)

- **Difficulty Rating**: 1094
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is playing with strings numbered $S_1, S_2, \dots, S_N$. To move from string $S_i$ to $S_{i+1}$, Chef skips all strings that lie strictly between these two values. We need to calculate the total number of strings skipped across all transitions from $S_1$ to $S_N$.

## Intuition & Mathematical Observation
For any two consecutive strings $S_i$ and $S_{i+1}$, the number of integers strictly between them is given by the formula:
$$\text{skipped} = |S_{i+1} - S_i| - 1$$

If $|S_{i+1} - S_i| \le 1$, then no strings are skipped (the result of the formula would be 0 or -1, so we treat it as 0). 

**Key Considerations:**
1. **Data Types**: Since $N$ can be up to $10^5$ and each $S_i$ up to $10^6$, the total sum can reach approximately $10^{11}$. This exceeds the capacity of a standard 32-bit `int`, so we must use `long long` to store the total count.
2. **Efficiency**: We can process the input in a single pass, calculating the difference between consecutive elements and adding it to a running total, which keeps the solution efficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of strings. We iterate through the array exactly once.
- **Space Complexity**: $O(N)$ to store the input array (or $O(1)$ if we process the input on-the-fly without storing it in a vector).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To move from string S_i to S_{i+1}, the number of strings skipped is:
 * abs(S_{i+1} - S_i) - 1.
 * 
 * We need to sum this value for all i from 1 to N-1.
 * Constraints:
 * T <= 10
 * N <= 10^5
 * S_i <= 10^6
 * 
 * The total sum can exceed the range of a 32-bit integer (10^5 * 10^6 = 10^11),
 * so we must use 'long long' for the accumulator.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> s(n);
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        
        long long total_skipped = 0;
        for (int i = 0; i < n - 1; ++i) {
            // The number of strings between S_i and S_{i+1} is |S_{i+1} - S_i| - 1
            long long diff = abs(s[i+1] - s[i]);
            if (diff > 0) {
                total_skipped += (diff - 1);
            }
        }
        
        cout << total_skipped << "\n";
    }
    
    return 0;
}
```