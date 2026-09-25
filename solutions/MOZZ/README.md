# [Endless Appetizers (MOZZ)](https://www.codechef.com/problems/MOZZ)

- **Difficulty Rating**: 752
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef initially eats $X$ mozzarella sticks. For every $30$ rupees he spends, he can order an additional stick. Given the total extra money $R$ he spends, we need to calculate the total number of sticks he consumes. Since each plate contains $Y$ sticks and Chef only orders a new plate after finishing the current one, we must determine the minimum number of plates required to accommodate the total number of sticks eaten.

## Intuition & Mathematical Observation
1. **Calculate Extra Sticks**: Since each extra stick costs 30 rupees, the number of extra sticks is given by $\lfloor R / 30 \rfloor$.
2. **Calculate Total Sticks**: The total number of sticks consumed ($S$) is the sum of the initial sticks and the extra sticks:
   $$S = X + \frac{R}{30}$$
3. **Calculate Plates**: Each plate contains $Y$ sticks. To find the number of plates required to cover $S$ sticks, we need to calculate $\lceil S / Y \rceil$.
4. **Integer Arithmetic**: In programming, the ceiling division $\lceil a / b \rceil$ can be efficiently calculated using integer division as `(a + b - 1) / b`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Calculate extra sticks: R / 30.
 * 2. Total sticks eaten: X + (R / 30).
 * 3. Plates required: ceil(Total sticks / Y).
 * Using integer arithmetic, ceil(a / b) is (a + b - 1) / b.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long X, Y, R;
        cin >> X >> Y >> R;

        // Calculate total sticks consumed
        long long extra_sticks = R / 30;
        long long total_sticks = X + extra_sticks;

        // Calculate ceil(total_sticks / Y) using integer division
        // Formula: (numerator + denominator - 1) / denominator
        long long plates = (total_sticks + Y - 1) / Y;

        cout << plates << "\n";
    }

    return 0;
}
```