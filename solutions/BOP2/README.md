# [Color Festival (BOP2)](https://www.codechef.com/problems/BOP2)

- **Difficulty Rating**: 588
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ friends, each associated with a specific color $C_i$. We need to arrange these friends in a sequence such that the total number of "jolts" (color changes) is minimized. A jolt occurs when we start the sequence and every time the color of the current friend differs from the color of the previous friend.

## Intuition & Mathematical Observation
To minimize the number of jolts, we should group all friends of the same color together. 

1. **Initial Jolt**: The first friend in the sequence always contributes 1 jolt because we transition from "no color" to the color of the first friend.
2. **Subsequent Jolts**: If we have $K$ distinct colors, we can arrange the friends in $K$ blocks, where each block contains all friends of a specific color.
   - The first block contributes 1 jolt.
   - Each transition between different color blocks contributes 1 additional jolt.
   - With $K$ blocks, there are $K-1$ transitions.
3. **Total Calculation**: Total jolts = $1 + (K - 1) = K$.

Thus, the minimum number of jolts required is exactly equal to the number of unique colors present in the input. We can efficiently find this by inserting all colors into a `std::set` and checking its size.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the implementation. Using a `std::set`, each insertion takes $O(\log K)$ where $K \le N$, leading to $O(N \log N)$ overall.
- **Space Complexity**: $O(N)$ to store the distinct colors in the set.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To minimize jolts, we group all identical colors together.
 * If there are K distinct colors, we will have K blocks of colors.
 * The total jolts will be K (1 for the start + K-1 transitions).
 */

void solve() {
    int N;
    cin >> N;
    set<int> distinct_colors;
    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        distinct_colors.insert(c);
    }
    
    // The number of jolts is equal to the number of unique colors.
    cout << distinct_colors.size() << "\n";
}

int main() {
    // Fast I/O for performance
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