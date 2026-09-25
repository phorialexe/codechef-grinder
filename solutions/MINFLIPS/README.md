# [Minimum number of Flips (MINFLIPS)](https://www.codechef.com/problems/MINFLIPS)

- **Difficulty Rating**: 781
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of size $N$ consisting only of $1$s and $-1$s, we want the sum of all elements to be $0$. We can perform an operation where we flip the sign of any element (change $1$ to $-1$ or vice versa). We need to find the minimum number of operations required to make the sum $0$. If it is impossible, output $-1$.

## Intuition & Mathematical Observation
1. **Parity Constraint**: The sum of $N$ elements, each being $1$ or $-1$, will have the same parity as $N$. If $N$ is odd, the sum will always be odd (and thus never $0$). Therefore, if $N \% 2 \neq 0$, the answer is $-1$.
2. **Target State**: If $N$ is even, for the sum to be $0$, we must have an equal number of $1$s and $-1$s. Specifically, we need exactly $N/2$ elements to be $1$ and $N/2$ elements to be $-1$.
3. **Calculating Flips**: 
   - Let $P$ be the count of $1$s and $M$ be the count of $-1$s.
   - If $P > N/2$, we have an excess of $1$s. We must flip $(P - N/2)$ of them to $-1$ to balance the array.
   - If $M > N/2$, we have an excess of $-1$s. We must flip $(M - N/2)$ of them to $1$ to balance the array.
   - If $P = M = N/2$, the sum is already $0$, so the answer is $0$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to count the occurrences of $1$ and $-1$.
- **Space Complexity**: $O(N)$ to store the array (though this could be optimized to $O(1)$ by counting on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let N be the number of elements.
 * Let P be the count of 1s and M be the count of -1s.
 * If N is odd, the sum can never be 0.
 * If N is even, we need the final count of 1s to be N/2 and -1s to be N/2.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int p = 0, m = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) p++;
        else m++;
    }

    // If N is odd, sum can never be 0
    if (n % 2 != 0) {
        cout << -1 << "\n";
        return;
    }

    // We need exactly n/2 ones and n/2 minus ones
    int target = n / 2;
    if (p > target) {
        cout << (p - target) << "\n";
    } else if (m > target) {
        cout << (m - target) << "\n";
    } else {
        cout << 0 << "\n";
    }
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