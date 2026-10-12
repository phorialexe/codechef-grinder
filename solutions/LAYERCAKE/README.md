# [Layered Cake (LAYERCAKE)](https://www.codechef.com/problems/LAYERCAKE)

- **Difficulty Rating**: 875
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two arrays, $A$ (size $N$) and $B$ (size $M$), representing the heights of two types of cake layers. We need to determine the total number of valid pairs $(A_i, B_j)$ such that the height of the second layer $B_j$ is strictly less than the height of the first layer $A_i$ ($B_j < A_i$).

## Intuition & Mathematical Observation
Given the constraints where $N, M \le 100$, the total number of possible pairs is at most $100 \times 100 = 10,000$. Since the number of test cases $T$ is also reasonable, a brute-force approach is highly efficient.

The problem asks us to count pairs $(i, j)$ that satisfy the condition $B_j < A_i$. We can achieve this by using two nested loops:
1. The outer loop iterates through each element of array $A$.
2. The inner loop iterates through each element of array $B$.
3. Inside the inner loop, we check if $B_j < A_i$. If true, we increment a counter.

This approach covers all possible combinations and directly implements the problem requirement.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \times M)$, where $T$ is the number of test cases. Given $N, M \le 100$, the total operations per test case are $10^4$, which is well within the 1-second time limit (typically allowing $\sim 10^8$ operations).
- **Space Complexity**: $O(N + M)$ to store the two input arrays.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two arrays A (size N) and B (size M).
 * We need to find the number of pairs (A_i, B_j) such that B_j < A_i.
 * 
 * Constraints:
 * N, M <= 100
 * A_i, B_i <= 100
 * 
 * Since N and M are small (up to 100), an O(N * M) approach per test case
 * is perfectly efficient. Total complexity O(T * N * M) = 100 * 100 * 100 = 10^6,
 * which easily fits within the 1s time limit.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    vector<int> B(M);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    
    long long count = 0;
    // Iterate through every pair (A_i, B_j)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // Check the constraint: second layer (B_j) < first layer (A_i)
            if (B[j] < A[i]) {
                count++;
            }
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}
```