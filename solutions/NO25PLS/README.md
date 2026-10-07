# [Imperfect Numbers (NO25PLS)](https://www.codechef.com/problems/NO25PLS)

- **Difficulty Rating**: 697
- **Solved in**: 3 attempt(s)

## Problem Summary
An integer $M$ is defined as "imperfect" if it is divisible by either 2 or 5, but **not both**. Given an integer $N$ ($1 \le N \le 100$), the goal is to find the minimum absolute difference $|N - M|$ such that $M$ is an imperfect number and $M > 0$.

## Intuition & Mathematical Observation
The condition "divisible by 2 or 5, but not both" is equivalent to the logical **XOR** operation: `(M % 2 == 0) ^ (M % 5 == 0)`.

- Numbers divisible by both 2 and 5 are multiples of 10 (e.g., 10, 20, 30...).
- The pattern of divisibility by 2 and 5 repeats every 10 integers.
- Since $N$ is small ($N \le 100$), we can use a "brute-force search" approach. We check numbers at distance $d = 0, 1, 2, \dots$ from $N$. Specifically, we check $N-d$ and $N+d$ simultaneously. The first $d$ that satisfies the condition is our answer. Because imperfect numbers are very frequent (they occur at least 6 times in every 10 integers), the loop will terminate almost immediately.

## Complexity Analysis
- **Time Complexity**: $O(T \times D)$, where $T$ is the number of test cases and $D$ is the maximum distance searched. Since an imperfect number is guaranteed to be found within a very small constant distance, this is effectively $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables for calculation.

## Solution Code

```cpp
#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * An integer M is "imperfect" if:
 * (M % 2 == 0 XOR M % 5 == 0)
 * 
 * Given N (1 <= N <= 100), we need to find min |N - M|.
 * Since the pattern of divisibility by 2 and 5 repeats every 10,
 * an imperfect number is guaranteed to be found within a very small distance.
 */

bool is_imperfect(int m) {
    if (m <= 0) return false;
    bool div2 = (m % 2 == 0);
    bool div5 = (m % 5 == 0);
    // XOR condition: divisible by 2 or 5, but not both.
    return (div2 != div5);
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Check distance d starting from 0.
    // Since N >= 1, the closest imperfect number will be found almost immediately.
    for (int d = 0; d <= 1000; ++d) {
        // Check N - d (must be positive)
        if (n - d > 0 && is_imperfect(n - d)) {
            cout << d << "\n";
            return;
        }
        // Check N + d
        if (is_imperfect(n + d)) {
            cout << d << "\n";
            return;
        }
    }
}

int main() {
    // Optimize I/O operations
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