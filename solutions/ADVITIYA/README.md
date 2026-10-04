# [Advitiya (ADVITIYA)](https://www.codechef.com/problems/ADVITIYA)

- **Difficulty Rating**: 844
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length 8, we need to transform it into the target string `"ADVITIYA"`. The transformation operation allows us to increment any character cyclically (e.g., 'A' becomes 'B', ..., 'Z' becomes 'A'). We need to calculate the minimum total number of operations required to transform $S$ into the target string.

## Intuition & Mathematical Observation
Since each character in the string is independent, we can calculate the cost to transform each character $S[i]$ to $target[i]$ individually and sum them up.

For any two characters $c_1$ and $c_2$, the number of cyclic increments required to change $c_1$ to $c_2$ is calculated using modular arithmetic:
$$\text{steps} = (c_2 - c_1 + 26) \pmod{26}$$

- If $c_2 \ge c_1$, the difference is simply $c_2 - c_1$.
- If $c_2 < c_1$, we wrap around the alphabet, which is handled by adding 26 before taking the modulo.

By iterating through the string of length 8 and applying this formula to each character pair, we obtain the total minimum operations.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string (fixed at 8). Since $N$ is constant, this is effectively $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the target string and the running sum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to transform string S into "ADVITIYA".
 * For each character S[i], we can increment it cyclically (A->B, ..., Z->A).
 * The number of steps to change character 'c1' to 'c2' is:
 * (c2 - c1 + 26) % 26.
 * Since the string length is fixed at 8, we iterate through each index 
 * and sum the steps required for each character.
 */

void solve() {
    string S;
    cin >> S;
    string target = "ADVITIYA";
    long long total_steps = 0;

    for (int i = 0; i < 8; ++i) {
        // Calculate cyclic distance between characters
        int diff = (target[i] - S[i] + 26) % 26;
        total_steps += diff;
    }

    cout << total_steps << "\n";
}

int main() {
    // Fast I/O
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