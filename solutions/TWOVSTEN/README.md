# [Two vs Ten (TWOVSTEN)](https://www.codechef.com/problems/TWOVSTEN)

- **Difficulty Rating**: 936
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $X$, we want to determine the minimum number of operations required to make $X$ divisible by 10. In one operation, we can multiply $X$ by 2. If it is impossible to make $X$ divisible by 10, we should output -1.

## Intuition & Mathematical Observation
To make a number divisible by 10, its last digit must be 0. Let's analyze the last digit of $X$ after multiplying by 2:

1. **If $X$ ends in 0**: $X$ is already divisible by 10. The number of operations required is **0**.
2. **If $X$ ends in 5**: Multiplying $X$ by 2 will result in a number ending in 0 (e.g., $5 \times 2 = 10$, $15 \times 2 = 30$). Thus, the number of operations required is **1**.
3. **If $X$ ends in any other digit (1, 2, 3, 4, 6, 7, 8, 9)**: 
   - Multiplying by 2 repeatedly will cycle through the last digits of the powers of 2. None of these operations will result in a number ending in 0 because the prime factorization of 10 is $2 \times 5$. If the number does not already contain a factor of 5 (i.e., it doesn't end in 0 or 5), multiplying by 2 will never introduce the factor of 5 required to make it divisible by 10. Therefore, it is **impossible**, and we output **-1**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing simple modulo arithmetic. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make X divisible by 10.
 * A number is divisible by 10 if its last digit is 0.
 * 
 * Logic:
 * 1. If X % 10 == 0: Already divisible, 0 turns.
 * 2. If X % 5 == 0 (and not 10): The last digit is 5. 5 * 2 = 10, 1 turn.
 * 3. Otherwise: Impossible to reach a multiple of 10, return -1.
 */

void solve() {
    long long X;
    cin >> X;
    
    if (X % 10 == 0) {
        cout << 0 << "\n";
    } else if (X % 5 == 0) {
        // Since it's not divisible by 10 but is divisible by 5, 
        // the last digit must be 5. Multiplying by 2 makes it end in 0.
        cout << 1 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```