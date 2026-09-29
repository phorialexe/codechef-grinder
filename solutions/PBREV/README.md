# [Problem Reviews (PBREV)](https://www.codechef.com/problems/PBREV)

- **Difficulty Rating**: 643
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a coding problem is "good" based on the scores provided by $N$ judges. A problem is considered "good" if and only if **every** judge gives a score strictly greater than 4. If even one judge provides a score of 4 or less, the problem is not "good."

## Intuition & Mathematical Observation
The condition for a problem to be "good" is defined by the logical conjunction of all scores being $> 4$. 
- We can iterate through the list of $N$ scores.
- We maintain a boolean flag `is_good`, initialized to `true`.
- As we read each score, if we encounter any value $S \le 4$, we immediately know the condition is violated. We set `is_good` to `false`.
- After checking all scores, if `is_good` remains `true`, we output "YES"; otherwise, we output "NO".

This approach is efficient because it processes each score exactly once and uses constant extra space.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of judges. Given the constraint that the sum of $N$ over all test cases is $\le 2000$, the total time complexity is $O(\sum N)$, which easily passes within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we only store a few variables (`n`, `score`, `is_good`) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A problem is 'good' if every judge gives a score > 4.
 * This means if any judge gives a score <= 4, the problem is not 'good'.
 * 
 * Constraints:
 * T <= 1000, N <= 1000, Sum of N <= 2000.
 * Time complexity per test case: O(N)
 * Total time complexity: O(Sum of N), which is well within the 1s limit.
 */

void solve() {
    int n;
    cin >> n;
    
    bool is_good = true;
    for (int i = 0; i < n; ++i) {
        int score;
        cin >> score;
        // If any score is <= 4, the problem is not good.
        if (score <= 4) {
            is_good = false;
        }
    }
    
    if (is_good) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```