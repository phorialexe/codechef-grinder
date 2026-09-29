# [Access Code Equality (WECNITK)](https://www.codechef.com/problems/WECNITK)

- **Difficulty Rating**: 355
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to verify if a given input string $S$ is exactly equal to the string `"WECNITK"`. If the input matches the target string exactly (case-sensitive), the program should output `"Welcome to Web Club!"`. Otherwise, it should output `"Access denied"`.

## Intuition & Mathematical Observation
The problem is a straightforward string comparison task. Since the constraints are minimal and the target string is fixed, we do not need complex algorithms or data structures. 

1. **Case Sensitivity**: The problem specifies that the comparison must be case-sensitive. Therefore, `"WECNITK"` is the only valid input; variations like `"WECnitk"` or `"wecnitk"` must be rejected.
2. **Input Handling**: We read the input string from standard input and use a simple `if-else` conditional statement to compare the input against the constant string `"WECNITK"`.
3. **Efficiency**: Given the string length is fixed at 7 characters, the comparison operation is $O(1)$ in terms of time complexity.

## Complexity Analysis
- **Time Complexity**: $O(L)$, where $L$ is the length of the input string. Since $L=7$ is a constant, this is effectively $O(1)$.
- **Space Complexity**: $O(L)$ to store the input string, which is $O(1)$ given the fixed length.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: WECNITK - Access Code Equality
 * The problem requires checking if the input string S is exactly "WECNITK".
 * Since the problem specifies that case sensitivity matters, we perform 
 * a direct string comparison.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // Read the input string
    if (cin >> s) {
        // Perform case-sensitive comparison
        if (s == "WECNITK") {
            cout << "Welcome to Web Club!" << "\n";
        } else {
            cout << "Access denied" << "\n";
        }
    }

    return 0;
}
```