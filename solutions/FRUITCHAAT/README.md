# [Chef and His Fruit Stand (FRUITCHAAT)](https://www.codechef.com/problems/FRUITCHAAT)

- **Difficulty Rating**: 822
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to make fruit chaats. Each fruit chaat requires exactly **2 bananas** and **1 apple**. Given $X$ bananas and $Y$ apples, determine the maximum number of fruit chaats Chef can prepare.

## Intuition & Mathematical Observation
To make a single fruit chaat, we need a specific ratio of ingredients: 2 bananas and 1 apple.
1. If we only consider bananas, the maximum number of chaats we can make is $\lfloor X / 2 \rfloor$.
2. If we only consider apples, the maximum number of chaats we can make is $Y$.

Since a chaat requires **both** ingredients, the total number of chaats is limited by the ingredient that runs out first. Therefore, the answer is the minimum of the two values calculated above:
$$\text{Result} = \min\left(\left\lfloor \frac{X}{2} \right\rfloor, Y\right)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each fruit chaat requires 2 bananas and 1 apple.
 * Given X bananas and Y apples:
 * - The number of chaats possible based on bananas is X / 2.
 * - The number of chaats possible based on apples is Y / 1 = Y.
 * Since both ingredients are required, the total number of chaats is the 
 * minimum of these two values: min(X / 2, Y).
 * 
 * Constraints: 0 <= X, Y <= 100.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate max chaats based on bananas (x/2) and apples (y)
        long long max_chaats_by_bananas = x / 2;
        long long max_chaats_by_apples = y;
        
        // The limiting factor determines the total number of chaats
        long long result = min(max_chaats_by_bananas, max_chaats_by_apples);
        
        cout << result << "\n";
    }
    
    return 0;
}
```