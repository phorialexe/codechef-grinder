# [Let Me Eat Cake! (CAKEHALF)](https://www.codechef.com/problems/CAKEHALF)

- **Difficulty Rating**: 753
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given two piles of cake slices, $A$ and $B$. In each step, Charlie chooses the larger pile and eats half of its slices (rounding up). This process repeats until the two piles are equal in size ($A = B$). We need to calculate the total number of slices Charlie eats throughout the process.

## Intuition & Mathematical Observation
The problem describes a direct simulation process. Since the constraints on $A$ and $B$ are small ($A, B \le 100$), we do not need a complex mathematical formula. 

1. **Rounding Up**: To calculate "half rounded up" using integer arithmetic, we use the formula `(n + 1) / 2`. For example, if $n=5$, $(5+1)/2 = 3$. If $n=4$, $(4+1)/2 = 2$.
2. **Simulation**: In each iteration of a `while` loop, we compare $A$ and $B$. We subtract the eaten amount from the larger pile and add that amount to a running total.
3. **Termination**: The loop continues as long as $A \neq B$. Once they are equal, the process stops, and we output the accumulated total.

## Complexity Analysis
- **Time Complexity**: $O(\log(\max(A, B)))$ per test case. Since we are effectively halving the larger number in each step, the number of operations is logarithmic relative to the input values. Given the constraints, this is extremely efficient.
- **Space Complexity**: $O(1)$, as we only use a few variables to track the pile sizes and the total count.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two integers A and B representing slices of cake.
 * While A != B, Charlie eats half (rounded up) of the larger pile.
 * We need to count the total number of slices eaten.
 * 
 * Since A, B <= 100, a direct simulation is perfectly efficient.
 * The number of operations will be small because the larger value 
 * decreases significantly in each step.
 */

void solve() {
    long long A, B;
    if (!(cin >> A >> B)) return;

    long long total_eaten = 0;

    while (A != B) {
        if (A > B) {
            // Charlie eats half of A, rounded up.
            // (A + 1) / 2 is the integer arithmetic equivalent of ceil(A / 2.0)
            long long eaten = (A + 1) / 2;
            total_eaten += eaten;
            A -= eaten;
        } else {
            // Charlie eats half of B, rounded up.
            long long eaten = (B + 1) / 2;
            total_eaten += eaten;
            B -= eaten;
        }
    }

    cout << total_eaten << "\n";
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