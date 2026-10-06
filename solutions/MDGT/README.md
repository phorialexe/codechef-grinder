# [Lost in the Fest!! (MDGT)](https://www.codechef.com/problems/MDGT)

- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary
Bhoomi is standing at the end of a line of $N$ people (index $N-1$). She wants to reach a position where her height $H_{current}$ is strictly greater than the heights of all people standing in front of her (indices $0$ to $current-1$). She can swap her position with the person immediately in front of her. We need to find the minimum number of swaps required to satisfy the condition.

## Intuition & Mathematical Observation
The problem asks for the minimum number of swaps to reach a "visible" position. Since $N$ is small ($N \le 100$), we can simulate the process step-by-step:

1. **Check Condition**: At any position `current_pos`, check if $H[current\_pos] > H[i]$ for all $i < current\_pos$.
2. **Termination**: If the condition is met, the current number of swaps is the answer.
3. **Simulation**: If the condition is not met, Bhoomi must move forward. Swapping with the person in front effectively moves her one index closer to the front. We increment the swap counter and repeat the check.
4. **Edge Case**: If $N=1$, she is already at the front, so the answer is $0$.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$. In the worst case, we perform $N$ swaps, and for each swap, we iterate through the array up to $N$ times to verify the condition. Given $N \le 100$, $N^2 = 10,000$, which easily passes within the time limit.
- **Space Complexity**: $O(N)$ to store the heights of the people in the line.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Bhoomi is at the last position (index N-1).
 * She can swap with the person in front of her.
 * She wants to reach a position 'i' such that her height H_N is strictly 
 * greater than all heights H_0, H_1, ..., H_{i-1}.
 * 
 * Since she moves one step at a time towards the front, we can simulate 
 * the process. At each step, we check if her current height is greater 
 * than all elements before her. If not, we swap her with the person 
 * immediately in front and increment the counter.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    if (N == 1) {
        cout << 0 << "\n";
        return;
    }

    int moves = 0;
    // Bhoomi is initially at index N-1
    int current_pos = N - 1;

    while (current_pos > 0) {
        // Check if Bhoomi can see the performance at current_pos
        bool can_see = true;
        for (int i = 0; i < current_pos; ++i) {
            if (H[i] >= H[current_pos]) {
                can_see = false;
                break;
            }
        }

        if (can_see) {
            break;
        }

        // Swap with the person in front
        swap(H[current_pos], H[current_pos - 1]);
        current_pos--;
        moves++;
    }

    cout << moves << "\n";
}

int main() {
    // Fast I/O
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