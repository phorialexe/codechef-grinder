# [Return the Change (RETURNCHANGE)](https://www.codechef.com/problems/RETURNCHANGE)

- **Difficulty Rating**: 763
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a cost $X$ (where $0 \le X \le 100$). The cost is rounded to the nearest multiple of 10. If the last digit of $X$ is 5 or greater, it rounds up to the next multiple of 10; otherwise, it rounds down. You need to calculate the amount returned to the customer if they pay with a 100-unit note, which is $100 - \text{rounded\_cost}$.

## Intuition & Mathematical Observation
The core of the problem is rounding a number $X$ to the nearest multiple of 10. 

In integer arithmetic, the expression `(X + 5) / 10` performs the following:
1. Adding 5 shifts the threshold for rounding.
2. Integer division by 10 truncates the decimal part.
3. Multiplying the result by 10 restores the magnitude to the nearest multiple of 10.

**Example:**
- If $X = 23$: $(23 + 5) / 10 = 28 / 10 = 2$. Then $2 \times 10 = 20$.
- If $X = 25$: $(25 + 5) / 10 = 30 / 10 = 3$. Then $3 \times 10 = 30$.
- If $X = 28$: $(28 + 5) / 10 = 33 / 10 = 3$. Then $3 \times 10 = 30$.

Once the `rounded_cost` is determined, the change returned is simply $100 - \text{rounded\_cost}$.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The cost X is rounded to the nearest multiple of 10.
 * If the last digit is 5 or greater, it rounds up.
 * If the last digit is less than 5, it rounds down.
 * This is equivalent to rounding X/10 to the nearest integer and multiplying by 10.
 * In C++, adding 5 to X and performing integer division by 10 (i.e., (X + 5) / 10) 
 * effectively performs this rounding logic.
 * Finally, the amount returned is 100 - rounded_cost.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;

        // Calculate the rounded cost
        // (x + 5) / 10 performs integer division, effectively rounding to nearest 10
        // Multiplying by 10 gives the rounded value.
        int rounded_cost = ((x + 5) / 10) * 10;

        // The amount returned is 100 minus the rounded cost
        int returned_amount = 100 - rounded_cost;

        cout << returned_amount << "\n";
    }

    return 0;
}
```