# [COVID Pandemic and Long Queue (COVIDLQ)](https://www.codechef.com/problems/COVIDLQ)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a queue represented by an array of size $N$ consisting of $0$s (empty space) and $1$s (a person). The rule for social distancing is that any two people must be separated by at least 5 empty spaces. In terms of indices, if two people are at positions $i$ and $j$ (where $i < j$), the condition is satisfied if $j - i \ge 6$. We need to determine if the given queue configuration follows this rule.

## Intuition & Mathematical Observation
The problem requires us to verify a constraint between consecutive occurrences of $1$s. 
1. If we encounter a person at index $i$, we need to check the position of the previously seen person (`last_pos`).
2. If the difference `i - last_pos` is less than $6$, the social distancing rule is violated.
3. To handle the first person in the queue correctly, we initialize `last_pos` to a value such that the condition `i - last_pos < 6` is never triggered for the first $1$ encountered (e.g., $-10$).
4. If we iterate through the entire array without finding any violations, the configuration is valid.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the queue. We perform a single pass through the array. Total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(N)$ to store the input array, though this could be optimized to $O(1)$ by processing the input values on the fly without storing them.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence of 0s and 1s representing a queue.
 * We need to ensure that for any two people (1s), the distance between them is at least 6.
 * If the indices of two people are i and j (where i < j), the distance is (j - i).
 * The condition is (j - i) >= 6.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Initialize with a value that ensures the first person is safe
    int last_pos = -10; 
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            // Check if the distance from the last person is at least 6
            if (i - last_pos < 6) {
                possible = false;
                break;
            }
            last_pos = i;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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