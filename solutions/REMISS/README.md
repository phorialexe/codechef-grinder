# [Chef and Remissness (REMISS)](https://www.codechef.com/problems/REMISS)

- **Difficulty Rating**: 928
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has two security guards who monitor the entry gate at different times. Guard 1 records $A$ entries, and Guard 2 records $B$ entries. We are told that the guards never sleep at the same time, meaning at least one guard is always present to record entries. We need to determine the minimum and maximum possible total number of entries that could have occurred.

## Intuition & Mathematical Observation
To find the total number of entries, we consider the constraints provided by the guards:

1.  **Minimum Entries**: Since at least one guard is always awake, the total number of entries must be at least the count recorded by the guard who was awake the most. If Guard 1 saw $A$ people and Guard 2 saw $B$ people, the total count cannot be less than $\max(A, B)$.
2.  **Maximum Entries**: The maximum number of entries occurs if the two guards never saw the same person (i.e., their shifts recorded entirely distinct sets of people). In this scenario, the total number of entries is simply the sum of the two counts: $A + B$.

Thus, for any given $A$ and $B$:
- **Min** = $\max(A, B)$
- **Max** = $A + B$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Guard 1 counts A entries.
 * Guard 2 counts B entries.
 * Since at least one guard is always awake, the total number of entries 
 * must be at least the maximum of the two counts (because the guard who 
 * was awake saw at least that many).
 * The maximum possible number of entries is the sum of the two counts 
 * (assuming they never saw the same entry, which is possible since they 
 * never sleep at the same time).
 * 
 * Minimum entries = max(A, B)
 * Maximum entries = A + B
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        // Minimum is the maximum of the two counts
        long long min_entries = max(a, b);
        
        // Maximum is the sum of the two counts
        long long max_entries = a + b;
        
        cout << min_entries << " " << max_entries << "\n";
    }
    
    return 0;
}
```