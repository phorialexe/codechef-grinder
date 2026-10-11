# [Pizza Cutting (PIZZAC)](https://www.codechef.com/problems/PIZZAC)

- **Difficulty Rating**: 566
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks whether it is possible to obtain exactly $N$ pieces of pizza by making cuts that all pass through the center of the circular pizza.

## Intuition & Mathematical Observation
When cutting a pizza through the center:
*   **0 cuts**: You have the whole pizza, which is **1** piece.
*   **1 cut**: You create **2** pieces.
*   **2 cuts**: You create **4** pieces.
*   **3 cuts**: You create **6** pieces.
*   **$k$ cuts ($k \ge 1$)**: You create **$2 \times k$** pieces.

From this, we can observe that:
1.  If $N = 1$, it is possible (0 cuts).
2.  If $N > 1$, the number of pieces must be even because every additional cut through the center adds exactly 2 new pieces to the total count.
3.  If $N$ is odd and $N > 1$, it is impossible to obtain that number of pieces.

Thus, the condition for "YES" is simply: `N == 1` or `N % 2 == 0`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time $O(1)$ arithmetic check.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform the check.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - A cut passes through the center of the circular pizza.
 * - 0 cuts result in 1 piece.
 * - 1 cut results in 2 pieces.
 * - 2 cuts result in 4 pieces.
 * - 3 cuts result in 6 pieces.
 * - In general, k cuts passing through the center result in 2*k pieces.
 * - Exception: 0 cuts result in 1 piece.
 * 
 * So, the possible number of pieces N are:
 * - If N = 1 (0 cuts)
 * - If N is even (N = 2*k, where k >= 1)
 * 
 * Therefore, the condition is: N == 1 OR N % 2 == 0.
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
        
        // Check if N is 1 or an even number
        if (n == 1 || n % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}
```