# [Thala For A Reason (THALA7)](https://www.codechef.com/problems/THALA7)

- **Difficulty Rating**: 235
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine if a given integer $N$ is equal to 7. If the input is 7, we must output "THALA"; otherwise, we must output "SADGE".

## Intuition & Mathematical Observation
The problem is a straightforward conditional check. The "Thala" reference is a popular meme in Indian cricket culture (referring to MS Dhoni and the number 7). Mathematically, we simply need to perform a comparison operation:
- If $N = 7$, the condition is true.
- If $N \neq 7$, the condition is false.

Since the input is a single integer, we can handle this using a simple `if-else` statement.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison and output operation, which takes constant time regardless of the input value.
- **Space Complexity**: $O(1)$ — We only use a single variable to store the input, requiring constant auxiliary space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: THALA7
 * Logic: Check if the input integer N is equal to 7.
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    if (cin >> n) {
        if (n == 7) {
            cout << "THALA" << "\n";
        } else {
            cout << "SADGE" << "\n";
        }
    }

    return 0;
}
```