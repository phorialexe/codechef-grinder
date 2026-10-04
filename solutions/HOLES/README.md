# [Holes in the text (HOLES)](https://www.codechef.com/problems/HOLES)

- **Difficulty Rating**: 1093
- **Solved in**: 2 attempt(s)

## Problem Summary
The objective is to calculate the total number of "holes" in a given string of uppercase English letters. Based on the visual representation of the letters, specific characters contain closed loops (holes):
- **2 holes**: 'B'
- **1 hole**: 'A', 'D', 'O', 'P', 'Q', 'R'
- **0 holes**: All other uppercase letters.

We need to process $T$ test cases and output the sum of holes for each string.

## Intuition & Mathematical Observation
The problem is a straightforward mapping task. Since the set of characters is limited to uppercase English letters (A-Z), we can define a helper function or a lookup table to return the hole count for any given character.

1. **Mapping**:
   - `B` is the only character with 2 holes.
   - `A, D, O, P, Q, R` each have 1 hole.
   - Every other character has 0 holes.
2. **Algorithm**:
   - For each test case, read the string.
   - Iterate through each character of the string.
   - Accumulate the hole count using the mapping defined above.
   - Print the total sum for the string.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the total number of characters across all test cases. We iterate through each character exactly once.
- **Space Complexity**: $O(1)$ (or $O(L)$ where $L$ is the length of the string), as we only store the current string and a few integer variables.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Mapping based on standard visual hole counting:
 * 1 hole: A, D, O, P, Q, R
 * 2 holes: B
 * 0 holes: C, E, F, G, H, I, J, K, L, M, N, S, T, U, V, W, X, Y, Z
 */

int get_holes(char c) {
    if (c == 'B') return 2;
    if (c == 'A' || c == 'D' || c == 'O' || c == 'P' || c == 'Q' || c == 'R') return 1;
    return 0;
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        string s;
        cin >> s;
        int total_holes = 0;
        for (char c : s) {
            total_holes += get_holes(c);
        }
        cout << total_holes << "\n";
    }
    return 0;
}
```