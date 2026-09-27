# [Coldplay Tickets (COLDPLAYTICK)](https://www.codechef.com/problems/COLDPLAYTICK)

- **Difficulty Rating**: 292
- **Solved in**: 1 attempt(s)

## Problem Summary
You are planning to attend a Coldplay concert with $N$ of your friends. Each ticket costs 5000 units. You need to calculate the total cost required to purchase tickets for yourself and all your friends.

## Intuition & Mathematical Observation
The problem asks for the total cost for a group of people. 
1. The group consists of **you** (1 person) and **$N$ friends**.
2. Therefore, the total number of people is $N + 1$.
3. Since each ticket costs 5000, the total cost is simply:
   $$\text{Total Cost} = (N + 1) \times 5000$$

Given the constraints ($1 \le N \le 5$), the result will easily fit within a standard integer type, though using `long long` is a safe practice in competitive programming to prevent overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic operation.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Coldplay Tickets
 * Logic: You need to buy tickets for yourself (1) and N friends.
 * Total people = N + 1.
 * Cost per ticket = 5000.
 * Total cost = (N + 1) * 5000.
 * Constraints: 1 <= N <= 5.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // Read the number of friends
    if (cin >> N) {
        // Calculate total people (N friends + 1 for yourself)
        long long total_people = (long long)N + 1;
        // Calculate total cost
        long long total_cost = total_people * 5000;
        // Output the result
        cout << total_cost << "\n";
    }

    return 0;
}
```