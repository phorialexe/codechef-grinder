# [Problem Difficulties (PROBDIFF)](https://www.codechef.com/problems/PROBDIFF)

- **Difficulty Rating**: 1321
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given four problems with specific difficulty levels. We need to partition these into two sets such that each set contains at least two problems, and all problems within a single set have distinct difficulty levels. We need to determine the maximum number of such sets we can form.

## Intuition & Mathematical Observation
Since we only have 4 problems, we can categorize the distribution of difficulty levels by calculating the frequency of each level. Let `max_freq` be the count of the most frequent difficulty level present in the input:

1.  **`max_freq == 4`**: All problems have the same difficulty (e.g., `{1, 1, 1, 1}`). It is impossible to form any set with distinct difficulties. **Result: 0**.
2.  **`max_freq == 3`**: Three problems are the same, and one is different (e.g., `{1, 1, 1, 2}`). We can form one set using one of the `1`s and the `2`. The remaining two `1`s cannot form a set. **Result: 1**.
3.  **`max_freq == 2`**: 
    *   Case `{1, 1, 2, 2}`: We can form two sets: `{1, 2}` and `{1, 2}`. **Result: 2**.
    *   Case `{1, 1, 2, 3}`: We can form two sets: `{1, 2}` and `{1, 3}`. **Result: 2**.
4.  **`max_freq == 1`**: All problems are distinct (e.g., `{1, 2, 3, 4}`). We can form two sets: `{1, 2}` and `{3, 4}`. **Result: 2**.

By observing these cases, the logic simplifies to checking the maximum frequency of any single difficulty level.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the input size is fixed at 4, counting frequencies using a map or a frequency array takes constant time.
- **Space Complexity**: $O(1)$. We only store the counts of 4 integers, which occupies constant space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 4 problems with difficulty levels A1, A2, A3, A4.
 * A problem set must have at least 2 problems, and all problems in a set must have distinct difficulties.
 * 
 * Simplified logic using frequency:
 * Let 'max_freq' be the count of the most frequent difficulty level.
 * - If max_freq == 4: Result 0.
 * - If max_freq == 3: Result 1.
 * - If max_freq == 2: Result 2.
 * - If max_freq == 1: Result 2.
 */

void solve() {
    vector<int> a(4);
    map<int, int> counts;
    for (int i = 0; i < 4; ++i) {
        cin >> a[i];
        counts[a[i]]++;
    }

    int max_freq = 0;
    for (auto const& [val, count] : counts) {
        max_freq = max(max_freq, count);
    }

    if (max_freq == 4) {
        cout << 0 << "\n";
    } else if (max_freq == 3) {
        cout << 1 << "\n";
    } else {
        // max_freq is 1 or 2
        cout << 2 << "\n";
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