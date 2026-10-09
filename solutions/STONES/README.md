# [Jewels and Stones (STONES)](https://www.codechef.com/problems/STONES)

- **Difficulty Rating**: 1248
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given two strings, $J$ (representing the types of stones that are jewels) and $S$ (representing the stones you have). Your task is to determine how many of the stones you have are actually jewels. A stone is a jewel if it exists in the string $J$. Note that the characters are case-sensitive.

## Intuition & Mathematical Observation
The problem asks us to check for the existence of characters from string $S$ within string $J$. Since the total number of possible characters is small (English alphabet, both uppercase and lowercase), we can optimize the lookup process:

1.  **Lookup Table**: Instead of searching through string $J$ for every character in $S$ (which would result in $O(|J| \times |S|)$ complexity), we can pre-process string $J$ into a frequency array or a boolean lookup table.
2.  **Boolean Array**: By creating a boolean array of size 128 (covering all standard ASCII characters), we can mark the presence of each jewel in $O(|J|)$ time.
3.  **Counting**: Once the lookup table is populated, we iterate through string $S$ once. For each character, we perform an $O(1)$ check against our boolean array. This reduces the overall complexity significantly.

## Complexity Analysis
- **Time Complexity**: $O(T \times (|J| + |S|))$, where $T$ is the number of test cases. Given the constraints $|J|, |S| \le 100$, this approach is extremely efficient and well within the time limits.
- **Space Complexity**: $O(1)$, as the boolean array size is constant (128), regardless of the input string lengths.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two strings: J (jewels) and S (stones).
 * We need to count how many characters in S are present in J.
 * 
 * Approach:
 * Since the character set is small (ASCII), we use a boolean array 
 * to store the characters present in J for O(1) lookup.
 * Then iterate through S and check if each character exists in the set.
 */

void solve() {
    string J, S;
    cin >> J >> S;

    // Use a boolean array to mark characters present in J.
    // ASCII range is 0-127, size 128 is sufficient.
    bool is_jewel[128] = {false};

    for (char c : J) {
        is_jewel[(int)c] = true;
    }

    long long count = 0;
    for (char c : S) {
        if (is_jewel[(int)c]) {
            count++;
        }
    }

    cout << count << "\n";
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