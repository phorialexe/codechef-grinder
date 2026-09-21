# [Complementary Strand in a DNA (DNASTRAND)](https://www.codechef.com/problems/DNASTRAND)

- **Difficulty Rating**: 660
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a DNA string consisting of characters 'A', 'T', 'C', and 'G', we need to generate its complementary strand. The rules for complementarity are:
- 'A' pairs with 'T'
- 'T' pairs with 'A'
- 'C' pairs with 'G'
- 'G' pairs with 'C'

## Intuition & Mathematical Observation
The problem is a direct mapping task. Since each character in the DNA alphabet has a unique, fixed complement, we can iterate through the input string and replace each character based on the defined rules. 

Using a simple `if-else` chain or a `switch` statement inside a loop allows us to transform the string in a single pass. Since the length of the string is $N$, we perform exactly $N$ operations to construct the result.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the DNA string. We traverse the string exactly once.
- **Space Complexity**: $O(N)$ to store the resulting complementary string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: DNASTRAND
 * The task is to replace each character in the DNA string with its complement:
 * A <-> T
 * C <-> G
 * 
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string result = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            result += 'T';
        } else if (s[i] == 'T') {
            result += 'A';
        } else if (s[i] == 'C') {
            result += 'G';
        } else if (s[i] == 'G') {
            result += 'C';
        }
    }
    cout << result << "\n";
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