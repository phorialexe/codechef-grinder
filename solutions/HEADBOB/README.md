# [Tanu and Head-bob (HEADBOB)](https://www.codechef.com/problems/HEADBOB)

- **Difficulty Rating**: 1065
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a string representing a sequence of gestures made by a person. The gestures are:
- `'I'`: Indicates the person is definitely **INDIAN**.
- `'Y'`: Indicates the person is definitely **NOT INDIAN**.
- `'N'`: A neutral gesture that doesn't provide enough information on its own.

We need to determine if the person is "INDIAN", "NOT INDIAN", or "NOT SURE" based on the sequence of gestures provided.

## Intuition & Mathematical Observation
The problem can be solved by checking for the presence of specific characters in the string:
1. **Priority 1 ('I')**: If the character `'I'` appears even once, the person is confirmed to be **INDIAN**. This takes precedence over all other gestures.
2. **Priority 2 ('Y')**: If `'I'` is not present, but `'Y'` appears, the person is confirmed to be **NOT INDIAN**.
3. **Default ('N')**: If neither `'I'` nor `'Y'` are present (meaning the string consists only of `'N'`s), we cannot determine the person's nationality, so the result is **NOT SURE**.

By iterating through the string once, we can track the existence of these characters and output the result based on the hierarchy above.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We traverse the string at most once per test case.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ if we process the characters as they are read.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - 'I' gesture: Only Indians use this. If 'I' is present, the person is INDIAN.
 * - 'Y' gesture: Only foreigners use this. If 'Y' is present (and no 'I'), the person is NOT INDIAN.
 * - 'N' gesture: Both might use this. If only 'N's are present, we are NOT SURE.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool found_i = false;
    bool found_y = false;

    for (char c : s) {
        if (c == 'I') {
            found_i = true;
            break; // 'I' is definitive, no need to check further
        } else if (c == 'Y') {
            found_y = true;
        }
    }

    if (found_i) {
        cout << "INDIAN" << "\n";
    } else if (found_y) {
        cout << "NOT INDIAN" << "\n";
    } else {
        cout << "NOT SURE" << "\n";
    }
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