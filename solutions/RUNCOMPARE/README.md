# [Running Comparison (RUNCOMPARE)](https://www.codechef.com/problems/RUNCOMPARE)

- **Difficulty Rating**: 899
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob run for $N$ days. On each day $i$, Alice runs $A_i$ distance and Bob runs $B_i$ distance. A day is considered "happy" if both individuals are satisfied with their performance relative to the other. Specifically, Alice is happy if $B_i \le 2 \cdot A_i$, and Bob is happy if $A_i \le 2 \cdot B_i$. We need to count the total number of days where both conditions are met simultaneously.

## Intuition & Mathematical Observation
The problem asks us to evaluate a condition for each day independently. For a given day $i$, the condition for a "happy day" is:
$$(B_i \le 2 \cdot A_i) \land (A_i \le 2 \cdot B_i)$$

Since the constraints are small ($N \le 100$ and $T \le 1000$), a simple linear scan through the arrays is sufficient. We iterate from $0$ to $N-1$, check the logical AND of the two inequalities for each index, and increment a counter whenever the condition evaluates to true. Using `long long` is a good practice to avoid overflow, although with $A_i, B_i \le 10^5$, standard `int` would also suffice as $2 \cdot 10^5$ fits well within a 32-bit signed integer.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot N)$, where $T$ is the number of test cases and $N$ is the number of days. Given the constraints, the total operations are roughly $10^5$, which easily passes within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the distances for Alice and Bob for each test case.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice is happy if Bob <= 2 * Alice.
 * Bob is happy if Alice <= 2 * Bob.
 * Both are happy if (Bob <= 2 * Alice) AND (Alice <= 2 * Bob).
 * 
 * Constraints:
 * N <= 100, T <= 1000.
 * A_i, B_i <= 10^5.
 * The condition involves multiplication by 2, which fits within standard 32-bit integers,
 * but using long long is safe practice to prevent any potential overflow.
 * Time complexity per test case: O(N).
 * Total time complexity: O(T * N), which is 10^5 operations, well within the 1s limit.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    int happy_days = 0;
    for (int i = 0; i < N; ++i) {
        // Alice is happy if B[i] <= 2 * A[i]
        // Bob is happy if A[i] <= 2 * B[i]
        if (B[i] <= 2 * A[i] && A[i] <= 2 * B[i]) {
            happy_days++;
        }
    }
    cout << happy_days << "\n";
}

int main() {
    // Fast I/O
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