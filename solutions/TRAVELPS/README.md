# [Travel Pass (TRAVELPS)](https://www.codechef.com/problems/TRAVELPS)

- **Difficulty Rating**: 1118
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a binary string $S$ of length $N$, where each character represents a type of travel:
- `'0'` represents an **inter-district** travel, which takes $A$ minutes.
- `'1'` represents an **inter-state** travel, which takes $B$ minutes.

The goal is to calculate the total time required to complete all travels described by the string $S$.

## Intuition & Mathematical Observation
The problem is a straightforward linear summation. Since each character in the string is independent, the total time is simply the sum of the time taken for each individual travel.

Mathematically, if $count_0$ is the number of '0's and $count_1$ is the number of '1's in the string, the total time $T$ is given by:
$$T = (count_0 \times A) + (count_1 \times B)$$

We can iterate through the string once, incrementing our total time based on the character encountered, which avoids the need to explicitly count the characters first.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We perform a single pass over the string.
- **Space Complexity**: $O(N)$ to store the input string. This can be optimized to $O(1)$ if we process the string character by character as it is read.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N.
 * '0' represents an inter-district travel requiring A minutes.
 * '1' represents an inter-state travel requiring B minutes.
 * We need to calculate the total time: (count of '0's * A) + (count of '1's * B).
 * 
 * Constraints:
 * T <= 100
 * N, A, B <= 100
 * Total time will not exceed 100 * 100 = 10,000, which fits in a standard int.
 */

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    long long total_time = 0;
    for (char c : S) {
        if (c == '0') {
            total_time += A;
        } else if (c == '1') {
            total_time += B;
        }
    }
    cout << total_time << "\n";
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