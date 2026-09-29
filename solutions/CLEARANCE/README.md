# [Clearance Sale (CLEARANCE)](https://www.codechef.com/problems/CLEARANCE)

- **Difficulty Rating**: 392
- **Solved in**: 3 attempt(s)

## Problem Summary
Chef is participating in a clearance sale where for every 2 t-shirts purchased, he receives 1 additional t-shirt for free. Given that Chef pays for $X$ t-shirts, we need to calculate the total number of t-shirts Chef acquires (purchased + free).

## Intuition & Mathematical Observation
The problem states that for every 2 t-shirts paid, 1 is given for free. This implies a ratio:
- If Chef pays for $X$ t-shirts, the number of free t-shirts he receives is $\lfloor X / 2 \rfloor$.
- Since the problem guarantees $X$ is an even number, $X / 2$ will always result in an exact integer.
- The total number of t-shirts is the sum of the paid t-shirts and the free t-shirts:
  $$\text{Total} = X + \frac{X}{2}$$

For example, if $X = 4$:
- Chef pays for 4.
- He gets $4 / 2 = 2$ free.
- Total = $4 + 2 = 6$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single arithmetic operation regardless of the input size.
- **Space Complexity**: $O(1)$ — We only use a few variables to store the input and the result, requiring constant extra space.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef pays for X t-shirts.
 * For every 2 t-shirts paid, he gets 1 free.
 * Number of free t-shirts = X / 2.
 * Total t-shirts = X + (X / 2).
 * 
 * Input Format:
 * The input contains a single even integer X.
 */

int main() {
    // Fast I/O setup for efficiency
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X;
    
    // Read the single integer X
    if (cin >> X) {
        // Calculation: Total = X + X/2
        // Since X is guaranteed to be even, X/2 is always an integer.
        long long total = X + (X / 2);
        
        cout << total << endl;
    }

    return 0;
}
```