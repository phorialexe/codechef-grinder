# [Divisible by 3 (MODULO3)](https://www.codechef.com/problems/MODULO3)

- **Difficulty Rating**: 978
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, we want to make at least one of them divisible by 3. In one operation, we can replace either $A$ or $B$ with the absolute difference $|A - B|$. We need to find the minimum number of operations required to reach a state where $A \pmod 3 = 0$ or $B \pmod 3 = 0$.

## Intuition & Mathematical Observation
Since we only care about divisibility by 3, we can work with the remainders $a = A \pmod 3$ and $b = B \pmod 3$. The possible values for $a$ and $b$ are $\{0, 1, 2\}$.

Let's analyze the states $(a, b)$:

1.  **If $a=0$ or $b=0$**: The condition is already satisfied. **(0 operations)**.
2.  **If $a=b$ (and $a, b \neq 0$)**:
    *   If we perform the operation $A = |A - B|$, the new remainder becomes $|a - a| \pmod 3 = 0$.
    *   Since we reached 0 in one step, the answer is **1 operation**.
3.  **If $\{a, b\} = \{1, 2\}$**:
    *   If we replace $A$ with $|A - B|$, the new remainder is $|1 - 2| \pmod 3 = 1$. The state becomes $(1, 2)$.
    *   If we replace $B$ with $|A - B|$, the new remainder is $|1 - 2| \pmod 3 = 1$. The state becomes $(1, 1)$.
    *   From the state $(1, 1)$, we know from the previous observation that it takes 1 more operation to reach 0.
    *   Therefore, starting from $\{1, 2\}$, it takes **2 operations**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic and conditional checks. Total time complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the remainders.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two numbers A and B. We want to reach a state where A % 3 == 0 or B % 3 == 0.
 * Let a = A % 3 and b = B % 3.
 * The operations are:
 * 1. A = |A - B|  => new_a = |a - b| % 3
 * 2. B = |A - B|  => new_b = |a - b| % 3
 * 
 * Possible states (a, b) where a, b in {0, 1, 2}:
 * - If a == 0 or b == 0: 0 operations.
 * - If a == b: 
 *      Operation 1: a becomes |a - a| = 0. (1 operation)
 *      Operation 2: b becomes |a - a| = 0. (1 operation)
 *      So, if a == b (and not 0), it takes 1 operation.
 * - If {a, b} is {1, 2}:
 *      Op 1: a becomes |1 - 2| = 1. State becomes (1, 2).
 *      Op 2: b becomes |1 - 2| = 1. State becomes (1, 1).
 *      From (1, 1), we know it takes 1 more operation to reach 0.
 *      So, from (1, 2), it takes 2 operations.
 */

void solve() {
    long long A, B;
    cin >> A >> B;
    
    int a = A % 3;
    int b = B % 3;
    
    if (a == 0 || b == 0) {
        cout << 0 << "\n";
    } else if (a == b) {
        cout << 1 << "\n";
    } else {
        // Case where {a, b} is {1, 2}
        cout << 2 << "\n";
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