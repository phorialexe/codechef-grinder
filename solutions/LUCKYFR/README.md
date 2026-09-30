# [Lucky Four (LUCKYFR)](https://www.codechef.com/problems/LUCKYFR)

- **Difficulty Rating**: 998
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, the task is to count the total number of times the digit '4' appears in its decimal representation. This must be performed for $T$ test cases.

## Intuition & Mathematical Observation
Since the input integer $N$ can be as large as $10^9$, we have two primary ways to process the digits:
1. **Mathematical approach**: Repeatedly use the modulo operator (`% 10`) to extract the last digit and integer division (`/ 10`) to remove it until the number becomes 0.
2. **String approach**: Read the input as a `std::string`. This allows us to iterate through each character of the number directly. 

The string approach is generally cleaner and less prone to edge-case errors (like handling the number 0). By iterating through the string and checking if each character is equal to `'4'`, we can maintain a counter and output the result for each test case.

## Complexity Analysis
- **Time Complexity**: $O(T \times D)$, where $T$ is the number of test cases and $D$ is the number of digits in the integer (at most 10 for $10^9$). This is highly efficient.
- **Space Complexity**: $O(D)$, as we store the number as a string of length $D$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: LUCKYFR - Lucky Four
 * Approach:
 * For each integer provided, we treat it as a string to easily iterate 
 * through each character and count the occurrences of the character '4'.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        string s;
        cin >> s;

        int count = 0;
        // Iterate through each character in the string
        for (char c : s) {
            if (c == '4') {
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}
```