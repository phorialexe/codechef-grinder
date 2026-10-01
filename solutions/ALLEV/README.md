# [All Even (ALLEV)](https://www.codechef.com/problems/ALLEV)

- **Difficulty Rating**: 617
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we are allowed to perform an operation repeatedly: add the last element to the second-to-last element and remove the last element. We need to determine if it is possible to reach a state where every element in the resulting array is even.

## Intuition & Mathematical Observation
The operation effectively allows us to "merge" the suffix of the array into a single element. Specifically, if we decide to stop merging at index $k$ (where $1 \le k \le N$), the resulting array will consist of the original elements $A_0, A_1, \dots, A_{k-2}$ followed by a single element representing the sum of the suffix $A_{k-1} + A_k + \dots + A_{N-1}$.

For the resulting array to consist entirely of even numbers:
1. Every element $A_i$ for $i < k-1$ must already be even.
2. The sum of the suffix starting from index $k-1$ to $N-1$ must be even.

We can iterate through all possible split points $k$ (from $1$ to $N$) and verify these two conditions. If any $k$ satisfies both, the answer is "Yes".

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ in the provided implementation, as we iterate through $k$ and calculate the suffix sum inside the loop. Given the constraints for a 617-rated problem, this is well within the time limits. (Note: This could be optimized to $O(N)$ using prefix sums or a running suffix sum, but $O(N^2)$ is sufficient here).
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to know if there exists a k such that all elements in the resulting 
 * array [A_0, A_1, ..., A_{k-2}, (A_{k-1} + ... + A_{N-1})] are even.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    bool possible = false;

    // Try every possible final array size k (from 1 to N)
    for (int k = 1; k <= N; ++k) {
        bool current_k_possible = true;
        
        // Check if all elements before the last one are even
        for (int i = 0; i < k - 1; ++i) {
            if (A[i] % 2 != 0) {
                current_k_possible = false;
                break;
            }
        }
        
        if (!current_k_possible) continue;
        
        // Check if the sum of the remaining suffix is even
        long long suffix_sum = 0;
        for (int i = k - 1; i < N; ++i) {
            suffix_sum += A[i];
        }
        
        if (suffix_sum % 2 == 0) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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