# [Ciel and A-B Problem (CIELAB)](https://www.codechef.com/problems/CIELAB)

- **Difficulty Rating**: 1136
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, calculate the result of $A - B$. However, the output must be a number that differs from the correct result by exactly one digit. A difference of "one digit" means that if you represent the numbers as strings, they differ at exactly one position.

## Intuition & Mathematical Observation
The problem asks us to provide an answer that is incorrect by exactly one digit. The simplest way to achieve this is to modify the last digit of the result $X = A - B$.

1. **Calculate the difference**: Let $X = A - B$.
2. **Modify the last digit**:
   - If we change the last digit, we must ensure we don't trigger a carry that changes other digits (e.g., changing $19$ to $20$ changes two digits: the $1$ becomes $2$ and the $9$ becomes $0$).
   - **Case 1**: If the last digit of $X$ is $9$, adding $1$ would result in a carry (e.g., $19 \to 20$). To avoid this, we subtract $1$ instead (e.g., $19 \to 18$).
   - **Case 2**: If the last digit of $X$ is not $9$, adding $1$ is perfectly safe because it will not trigger a carry (e.g., $12 \to 13$).
   
This logic guarantees that the result is always a valid integer and differs from the true $A - B$ by exactly one digit.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as we are performing a single subtraction and a constant-time conditional check.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to calculate A - B and output a result that differs by exactly one digit.
 * 
 * Strategy:
 * Calculate X = A - B.
 * If X % 10 == 9, change the last digit to 8 (X - 1).
 * Otherwise, change the last digit to X + 1.
 * This ensures the number of digits remains the same and we only change one digit.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    if (!(cin >> a >> b)) return 0;

    int diff = a - b;

    // If the last digit is 9, subtracting 1 is safe (e.g., 19 -> 18).
    // If the last digit is not 9, adding 1 is safe (e.g., 12 -> 13).
    if (diff % 10 == 9) {
        diff -= 1;
    } else {
        diff += 1;
    }

    cout << diff << "\n";

    return 0;
}
```