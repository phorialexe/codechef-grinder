# [Payment Scheme (PAYSC)](https://www.codechef.com/problems/PAYSC)

- **Difficulty Rating**: 213
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine the minimum payment amount between two different schemes for a given value $X$:
1. **Scheme 1**: A base payment of 100 plus 4 times the value of $X$ ($100 + 4X$).
2. **Scheme 2**: A fixed payment of 300.

We are given $X$ and must output the smaller of the two calculated values.

## Intuition & Mathematical Observation
The problem is a straightforward comparison task. We are given two mathematical expressions:
* $f(X) = 100 + 4X$
* $g(X) = 300$

To find the minimum payment, we simply calculate both values and use the `min()` function. 
* **Note on Constraints**: While $X$ is small in this specific problem, using `long long` for calculations is a good practice to prevent potential overflow in similar problems, though `int` would suffice here.
* **Debugging Note**: The initial attempt failed because it incorrectly anticipated multiple test cases (a common pattern in CodeChef problems). Adjusting the code to handle a single input $X$ resolved the issue.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a constant number of arithmetic operations and a comparison, regardless of the input size.
- **Space Complexity**: $O(1)$ — We only store a single integer $X$ and the results of the two schemes, requiring constant auxiliary space.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Scheme 1: 100 + 4 * X
 * Scheme 2: 300
 * We need to find min(100 + 4 * X, 300).
 * 
 * Debugging Note: The previous attempt incorrectly assumed multiple test cases.
 * The problem input format specifies a single integer X.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (cin >> X) {
        // Calculate both schemes
        long long scheme1 = 100 + (4LL * X);
        long long scheme2 = 300;
        
        // Output the minimum of the two
        cout << min(scheme1, scheme2) << endl;
    }
    
    return 0;
}
```