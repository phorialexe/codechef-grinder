# [Digit Sum Parities (DIGSMPAR)](https://www.codechef.com/problems/DIGSMPAR)

- **Difficulty Rating**: 1077
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to find the smallest integer $X > N$ such that the parity of the sum of digits of $X$ is different from the parity of the sum of digits of $N$.

## Intuition & Mathematical Observation
The parity of the sum of digits of an integer $N$ changes almost every time we increment $N$ by 1. 

- When we increment $N$ to $N+1$, if the last digit is not 9, the sum of digits increases by exactly 1, which flips the parity.
- If the last digit is 9, a carry occurs (e.g., $19 \to 20$). The sum of digits changes from $S$ to $S - 9 \times k + 1$, where $k$ is the number of trailing nines. Even in these cases, the parity will flip within a very small number of increments.

Because the parity flips so frequently, a simple linear search starting from $N+1$ is guaranteed to find the answer $X$ almost immediately. The maximum number of increments required is very small (at most 10), making this approach highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(T \times K \times \log_{10}(N))$, where $T$ is the number of test cases, $K$ is the small constant number of increments (at most 10), and $\log_{10}(N)$ is the cost of calculating the digit sum. Given $N \le 10^9$, this is well within the time limits.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current number and its digit sum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N and need to find the smallest X > N such that
 * parity(digitSum(N)) != parity(digitSum(X)).
 * 
 * Since N < 10^9, the digit sum is at most 9 * 9 = 81.
 * The parity of the digit sum changes very frequently as we increment N.
 * Specifically, incrementing N by 1 changes the digit sum parity unless
 * the last digit is 9 (which causes a carry).
 * Even with carries, the parity will flip within a very small number of increments.
 * A simple linear search starting from N+1 will be extremely efficient.
 */

int getDigitSum(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    long long n;
    cin >> n;
    
    int targetParity = getDigitSum(n) % 2;
    long long x = n + 1;
    
    while (true) {
        if ((getDigitSum(x) % 2) != targetParity) {
            cout << x << "\n";
            return;
        }
        x++;
    }
}

int main() {
    // Optimize I/O operations
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