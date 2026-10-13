# [Chef and Glove (CHEGLOVE)](https://www.codechef.com/problems/CHEGLOVE)

- **Difficulty Rating**: 1104
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ fingers with specific lengths and a glove with $N$ sheaths of specific lengths. A finger fits into a sheath if the finger's length is less than or equal to the sheath's length. We need to determine if the glove can be worn in the "front" orientation (finger $i$ in sheath $i$), the "back" orientation (finger $i$ in sheath $N-i+1$), or both, or neither.

## Intuition & Mathematical Observation
The problem asks us to verify two distinct conditions:
1. **Front Orientation**: For every index $i$ from $0$ to $N-1$, the condition $L[i] \le G[i]$ must hold.
2. **Back Orientation**: For every index $i$ from $0$ to $N-1$, the condition $L[i] \le G[N-1-i]$ must hold (using 0-based indexing).

By iterating through the arrays once for each condition, we can determine the validity of both orientations. We use two boolean flags, `front` and `back`, initialized to `true`. If we encounter any index where the condition fails, we set the respective flag to `false` and break the loop early. Finally, we compare the states of these flags to print the required output.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of fingers. We perform two linear passes over the arrays. Given $T \le 10$ and $N \le 10^5$, the total operations are roughly $2 \times 10^6$, which easily fits within the 1.5s time limit.
- **Space Complexity**: $O(N)$ to store the finger and sheath length arrays.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N fingers with lengths L[i] and N sheaths with lengths G[i].
 * Front orientation: Finger i fits in sheath i if L[i] <= G[i] for all i.
 * Back orientation: Finger i fits in sheath (N-i-1) if L[i] <= G[N-i-1] for all i.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> L(N), G(N);
    for (int i = 0; i < N; ++i) cin >> L[i];
    for (int i = 0; i < N; ++i) cin >> G[i];

    bool front = true;
    for (int i = 0; i < N; ++i) {
        if (L[i] > G[i]) {
            front = false;
            break;
        }
    }

    bool back = true;
    for (int i = 0; i < N; ++i) {
        // In back orientation, finger i (0-indexed) goes into sheath N-1-i
        if (L[i] > G[N - 1 - i]) {
            back = false;
            break;
        }
    }

    if (front && back) {
        cout << "both" << "\n";
    } else if (front) {
        cout << "front" << "\n";
    } else if (back) {
        cout << "back" << "\n";
    } else {
        cout << "none" << "\n";
    }
}

int main() {
    // Fast I/O setup
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