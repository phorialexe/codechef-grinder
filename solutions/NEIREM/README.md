# [Remaining Neighborhoods (NEIREM)](https://www.codechef.com/problems/NEIREM)

- **Difficulty Rating**: 319
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to calculate the number of neighborhoods remaining in a city that has a total of 100 neighborhoods. Given an integer $N$, representing the number of neighborhoods already visited, we need to output the difference between the total number of neighborhoods (100) and the number of visited neighborhoods ($N$).

## Intuition & Mathematical Observation
The problem is a straightforward arithmetic task. Since the total number of neighborhoods is fixed at 100, the number of remaining neighborhoods is simply the result of the subtraction:
$$\text{Remaining} = 100 - N$$
Given the constraints $0 \le N \le 100$, the result will always be a non-negative integer between 0 and 100, fitting well within standard integer data types.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single subtraction operation regardless of the input size.
- **Space Complexity**: $O(1)$ — The solution uses a constant amount of extra space to store the input and the result.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem: NEIREM
 * The city has 100 neighborhoods in total.
 * Given N (number of visited neighborhoods), we need to find (100 - N).
 * Constraints: 0 <= N <= 100.
 */

int main() {
    // Optimize I/O operations for faster execution
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    // Read the single integer N as specified in the input format.
    if (std::cin >> n) {
        // Calculate the remaining neighborhoods
        int remaining = 100 - n;
        // Output the result
        std::cout << remaining << std::endl;
    }

    return 0;
}
```