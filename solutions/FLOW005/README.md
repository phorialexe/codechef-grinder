# [Smallest Numbers of Notes (FLOW005)](https://www.codechef.com/problems/FLOW005)

- **Difficulty Rating**: 839
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an amount $N$, we need to find the minimum number of currency notes required to represent this amount. The available denominations are 1, 2, 5, 10, 50, and 100.

## Intuition & Mathematical Observation
This problem is a classic application of the **Greedy Algorithm**. 

Since the currency system provided (1, 2, 5, 10, 50, 100) is "canonical" (meaning each denomination is a multiple of smaller ones or allows for an optimal greedy choice), we can always achieve the minimum number of notes by repeatedly taking the largest possible denomination that is less than or equal to the remaining amount.

**Steps:**
1. Sort the denominations in descending order: $\{100, 50, 10, 5, 2, 1\}$.
2. For each denomination, calculate how many notes of that value can fit into the current amount $N$ using integer division (`N / denomination`).
3. Add this count to our total.
4. Update $N$ to the remainder (`N % denomination`) and proceed to the next smaller denomination.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the number of denominations is fixed (6), the loop runs a constant number of times regardless of the input size $N$.
- **Space Complexity**: $O(1)$, as we only use a fixed-size array to store the denominations and a few integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Smallest Numbers of Notes (FLOW005)
 * Strategy: This is a classic greedy problem. Since the denominations are 
 * 1, 2, 5, 10, 50, 100, we can always take the largest possible denomination 
 * that is less than or equal to the remaining amount to achieve the minimum 
 * number of notes.
 */

void solve() {
    int n;
    cin >> n;
    
    int denominations[] = {100, 50, 10, 5, 2, 1};
    int count = 0;
    
    for (int i = 0; i < 6; ++i) {
        if (n >= denominations[i]) {
            // Add the number of notes of this denomination
            count += n / denominations[i];
            // Update n to the remaining amount
            n %= denominations[i];
        }
    }
    
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}
```