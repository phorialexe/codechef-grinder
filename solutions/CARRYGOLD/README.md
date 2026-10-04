# [Gold Mining (CARRYGOLD)](https://www.codechef.com/problems/CARRYGOLD)

- **Difficulty Rating**: 880
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef and his $N$ friends want to carry $X$ kg of gold. Each person (including Chef) can carry a maximum of $Y$ kg of gold. We need to determine if the group has enough total capacity to carry all $X$ kg of gold.

## Intuition & Mathematical Observation
1. **Total People**: The group consists of Chef plus his $N$ friends, resulting in a total of $(N + 1)$ people.
2. **Total Capacity**: Since each of the $(N + 1)$ people can carry $Y$ kg, the total capacity of the group is $(N + 1) \times Y$.
3. **Condition**: The group can carry the gold if their total capacity is greater than or equal to the required amount $X$.
   - If $(N + 1) \times Y \ge X$, output `YES`.
   - Otherwise, output `NO`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Given $T$ test cases, the total time complexity is $O(T)$, which is well within the limits for $T \le 1000$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform the calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total number of people = N + 1 (Chef + N friends).
 * Each person can carry at most Y kg of gold.
 * Total capacity = (N + 1) * Y.
 * We need to check if total capacity >= X.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;
        
        // Total capacity is (number of people) * (capacity per person)
        // Using long long to prevent potential overflow, though int suffices for these constraints.
        long long total_capacity = (n + 1) * y;
        
        if (total_capacity >= x) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```