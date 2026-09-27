# [Chef and digits of a number (LONGSEQ)](https://www.codechef.com/problems/LONGSEQ)

- **Difficulty Rating**: 1209
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $D$ consisting only of digits '0' and '1', determine if it is possible to make all digits in the string identical by flipping **exactly one** digit. A flip changes a '0' to a '1' or a '1' to a '0'.

## Intuition & Mathematical Observation
To make all digits in the string the same, we have two possible target states:
1. **All digits become '1'**: This is only possible if there is exactly one '0' in the original string and all other digits are '1'.
2. **All digits become '0'**: This is only possible if there is exactly one '1' in the original string and all other digits are '0'.

Let $N$ be the length of the string, $count_0$ be the number of '0's, and $count_1$ be the number of '1's.
- To reach the first state, we need $count_0 = 1$ and $count_1 = N - 1$.
- To reach the second state, we need $count_1 = 1$ and $count_0 = N - 1$.

If either of these conditions is met, the answer is "Yes"; otherwise, it is "No".

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once to count the occurrences of '0's and '1's.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if processing character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string D consisting of '0's and '1's.
 * We want to make all digits the same by flipping exactly one digit.
 * 
 * Let count0 be the number of '0's and count1 be the number of '1's.
 * 
 * Case 1: Make all digits '1'.
 * This is possible if we have exactly one '0' and the rest are '1's.
 * 
 * Case 2: Make all digits '0'.
 * This is possible if we have exactly one '1' and the rest are '0's.
 */

void solve() {
    string s;
    cin >> s;
    
    int count0 = 0;
    int count1 = 0;
    
    for (char c : s) {
        if (c == '0') count0++;
        else count1++;
    }
    
    // Check if either condition for flipping exactly one digit is met
    if ((count0 == 1 && count1 == (int)s.length() - 1) || 
        (count1 == 1 && count0 == (int)s.length() - 1)) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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