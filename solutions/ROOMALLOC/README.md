# [Room Allocation (ROOMALLOC)](https://www.codechef.com/problems/ROOMALLOC)

- **Difficulty Rating**: 729
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ colleges, each with a specific number of members $A_i$. The constraints are:
1. People from different colleges cannot share a room.
2. Each room can accommodate at most 2 people.
We need to calculate the minimum number of rooms required to accommodate all members from all colleges.

## Intuition & Mathematical Observation
Since members from different colleges cannot share rooms, we can calculate the number of rooms required for each college independently and then sum them up.

For a college with $A_i$ members:
- If $A_i$ is even, the number of rooms needed is exactly $A_i / 2$.
- If $A_i$ is odd, we need $(A_i - 1) / 2$ rooms for the pairs, plus 1 additional room for the remaining person, totaling $(A_i + 1) / 2$ rooms.

Both cases can be unified using integer division: `(A_i + 1) / 2`. This formula effectively performs a "ceiling division" of $A_i$ by 2, which is the standard way to calculate the number of containers of size 2 needed for $A_i$ items.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of colleges. We iterate through the list of colleges exactly once.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the running total.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each college has A_i members.
 * People from different colleges cannot share a room.
 * Each room can hold at most 2 people.
 * 
 * For a single college with A_i members:
 * If A_i is even, we need A_i / 2 rooms.
 * If A_i is odd, we need (A_i + 1) / 2 rooms.
 * This can be simplified using integer division: (A_i + 1) / 2.
 * 
 * Total rooms = Sum of rooms needed for each college.
 * Constraints: N <= 100, A_i <= 100.
 * The total number of rooms will not exceed 100 * 50 = 5000, 
 * which fits easily into a standard integer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        long long total_rooms = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            // Calculate rooms for current college: ceil(a / 2.0)
            // Using integer arithmetic: (a + 1) / 2
            total_rooms += (a + 1) / 2;
        }
        cout << total_rooms << "\n";
    }
    return 0;
}
```