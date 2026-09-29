# [Yoga Day (YOGADAY)](https://www.codechef.com/problems/YOGADAY)

- **Difficulty Rating**: 264
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine how many full rounds of "Surya Namaskar" can be completed given a total number of yoga poses $N$. We are told that one complete round consists of exactly 12 poses. We need to output the total number of full rounds possible.

## Intuition & Mathematical Observation
Since each round requires 12 poses, we are looking for how many times 12 fits into the total number $N$. In programming, this is a classic application of **integer division**. 

When we perform `N / 12` using integer types in C++, the fractional part is automatically truncated, effectively giving us the floor of the division, which represents the count of complete rounds.

**Example:**
- If $N = 25$: $25 / 12 = 2$ (with a remainder of 1). The answer is 2.
- If $N = 11$: $11 / 12 = 0$. The answer is 0.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as it involves a single arithmetic division operation.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each round of Surya Namaskar consists of 12 yoga poses.
 * Given N total poses, the number of completed rounds is the integer division of N by 12.
 * 
 * Constraints:
 * 1 <= N <= 100
 * Time Complexity: O(1) per test case
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // Read the total number of poses
    if (cin >> n) {
        // Calculate completed rounds using integer division
        int rounds = n / 12;
        cout << rounds << "\n";
    }

    return 0;
}
```