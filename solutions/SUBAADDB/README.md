# [Sub A Add B (SUBAADDB)](https://www.codechef.com/problems/SUBAADDB)

- **Difficulty Rating**: 817
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a string of length $N$. In each operation, we can replace a substring of length $A$ with a substring of length $B$. This process continues as long as the current length of the string is at least $A$. We need to find the final length of the string once no more operations can be performed.

## Intuition & Mathematical Observation
The problem describes a process where the string length changes by a constant amount in each step. Specifically, if the current length is $L$, replacing $A$ characters with $B$ characters results in a new length of $L - A + B$.

Since the problem constraints state that $N$ is small (up to 100), we do not need a complex mathematical formula involving division or modulo. A simple `while` loop simulation is sufficient:
1. Check if the current length $N$ is greater than or equal to $A$.
2. If true, update $N$ to $N - A + B$.
3. Repeat until $N < A$.

**Note:** If $A \le B$, the string length would increase or stay the same, potentially leading to an infinite loop. However, based on the problem context, we assume the process terminates (i.e., $A > B$).

## Complexity Analysis
- **Time Complexity**: $O(T \times \frac{N}{A-B})$, where $T$ is the number of test cases. Given $N \le 100$, this simulation runs in constant time relative to the constraints.
- **Space Complexity**: $O(1)$, as we only use a few variables to track the state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with a string of length N.
 * In each step, we replace a substring of length A with a substring of length B.
 * This reduces the total length of the string by (A - B).
 * We repeat this as long as the current length L >= A.
 * 
 * Since N is small (up to 100), a simple simulation loop is perfectly efficient.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        // Simulation of the process
        // While the current length is at least A, perform the replacement
        while (n >= a) {
            n = n - a + b;
        }

        cout << n << "\n";
    }

    return 0;
}
```