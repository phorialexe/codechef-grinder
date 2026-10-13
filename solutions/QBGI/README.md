# [Bar Queue (QBGI)](https://www.codechef.com/problems/QBGI)

- **Difficulty Rating**: 821
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine how many people can enter a bar before the gate closes. The gate closes if the number of boys ($B$) currently in the queue exceeds twice the number of girls ($G$) currently in the queue (i.e., $B > 2 \times G$). We are given the sequence of people arriving as a string $S$ of length $N$. We need to output the total number of people who successfully entered the bar.

## Intuition & Mathematical Observation
The problem is a straightforward simulation. Since we need to find the exact point where the condition $B > 2 \times G$ is first satisfied, we can process the string character by character:

1. Maintain two counters: `boys` and `girls`.
2. Iterate through the string $S$. For every character:
   - Increment the corresponding counter.
   - Increment a total `allowed` counter.
   - Immediately check if `boys > 2 * girls`.
3. If the condition is met, the gate closes. The current person is the last one to be counted, and we stop the process.
4. If we reach the end of the string without the condition being met, all $N$ people have entered.

This greedy simulation works because the condition is checked incrementally at every step, ensuring we capture the first instance where the rule is violated.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once, performing constant-time operations at each step.
- **Space Complexity**: $O(N)$ to store the input string $S$. If we processed the input character by character without storing the string, the auxiliary space complexity would be $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to iterate through the string S and keep track of the number of boys (B)
 * and girls (G) who have entered the bar.
 * The condition for closing the gate is: boys > 2 * girls.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int boys = 0;
    int girls = 0;
    int allowed = 0;

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'B') {
            boys++;
        } else {
            girls++;
        }
        
        allowed++;
        
        // Check if the condition is met
        if (boys > 2 * girls) {
            break;
        }
    }

    cout << allowed << "\n";
}

int main() {
    // Fast I/O
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