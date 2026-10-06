# [Alternating String (ALTSTR)](https://www.codechef.com/problems/ALTSTR)

- **Difficulty Rating**: 1116
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ consisting of '0's and '1's, we want to rearrange the characters of the string to maximize the length of the longest alternating substring. An alternating string is one where no two adjacent characters are the same (e.g., "0101" or "1010").

## Intuition & Mathematical Observation
To maximize the length of an alternating substring, we should try to interleave the '0's and '1's as much as possible. Let $c_0$ be the count of '0's and $c_1$ be the count of '1's in the string.

1.  **Case 1: $c_0 = c_1$**
    If the counts are equal, we can perfectly alternate them (e.g., "0101..." or "1010..."). In this case, we can use all $N$ characters to form an alternating string of length $N$.

2.  **Case 2: $c_0 \neq c_1$**
    Assume without loss of generality that $c_0 < c_1$. We can place all $c_0$ zeros and surround them with ones. 
    - We can place a '1' before every '0' and one '1' after the last '0'. 
    - This creates a pattern like `1 0 1 0 1 ... 0 1`.
    - The number of '0's used is $c_0$, and the number of '1's used is $c_0 + 1$.
    - The total length is $c_0 + (c_0 + 1) = 2 \cdot c_0 + 1$.
    - Since $c_0 = \min(c_0, c_1)$, the formula becomes $2 \cdot \min(c_0, c_1) + 1$.

By combining these observations, if $c_0 = c_1$, the answer is $N$. Otherwise, the answer is $2 \cdot \min(c_0, c_1) + 1$.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once to count the occurrences of '0's and '1's.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ if we process the string character by character (though $O(N)$ is standard for storing the input).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We count the number of '0's (c0) and '1's (c1).
 * If c0 == c1, we can alternate all characters, resulting in length N.
 * If c0 != c1, we can use all of the minority character and one extra of the 
 * majority character to form an alternating sequence of length 2 * min(c0, c1) + 1.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int c0 = 0, c1 = 0;
    for (char c : S) {
        if (c == '0') c0++;
        else c1++;
    }

    if (c0 == c1) {
        cout << N << "\n";
    } else {
        cout << 2 * min(c0, c1) + 1 << "\n";
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