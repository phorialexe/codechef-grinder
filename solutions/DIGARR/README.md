# [Rearranging digits to get a multiple of 5 (DIGARR)](https://www.codechef.com/problems/DIGARR)

- **Difficulty Rating**: 949
- **Solved in**: 2 attempt(s)

## Problem Summary
Given a number $N$ represented as a string of $D$ digits, determine if it is possible to rearrange its digits to form a new number that is a multiple of 5.

## Intuition & Mathematical Observation
The divisibility rule for 5 states that a number is a multiple of 5 if and only if its last digit is either **0** or **5**. 

Since we are allowed to rearrange the digits of the given number $N$ in any order, we do not need to worry about the original sequence. We simply need to check if the set of digits contains at least one '0' or at least one '5'. If such a digit exists, we can place it at the end of the number, thereby satisfying the condition for the number to be a multiple of 5. If neither '0' nor '5' is present, it is impossible to form a multiple of 5.

## Complexity Analysis
- **Time Complexity**: $O(D)$ per test case, where $D$ is the number of digits in the string. We perform a single linear scan through the string to check for the presence of the required characters.
- **Space Complexity**: $O(D)$ to store the input string of digits.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

/**
 * Problem Analysis:
 * A number is a multiple of 5 if and only if its last digit is 0 or 5.
 * Therefore, we can rearrange the digits of N to form a multiple of 5
 * if and only if the string N contains at least one '0' or at least one '5'.
 * 
 * Time Complexity: O(D) per test case, where D is the number of digits.
 * Space Complexity: O(D) to store the string of digits.
 */

using namespace std;

void solve() {
    int D;
    if (!(cin >> D)) return;
    string N;
    cin >> N;

    bool found = false;
    // Iterate through the string to check for the existence of '0' or '5'
    for (int i = 0; i < D; ++i) {
        if (N[i] == '0' || N[i] == '5') {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```