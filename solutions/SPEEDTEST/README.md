# [Speed Limit Test (SPEEDTEST)](https://www.codechef.com/problems/SPEEDTEST)

- **Difficulty Rating**: 718
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob both travel a certain distance in a certain amount of time. Alice travels distance $A$ in time $X$, and Bob travels distance $B$ in time $Y$. We need to determine who is traveling faster, or if they are traveling at the same speed.

## Intuition & Mathematical Observation
The speed of an object is calculated as $\text{Speed} = \frac{\text{Distance}}{\text{Time}}$.
- Alice's speed: $S_A = \frac{A}{X}$
- Bob's speed: $S_B = \frac{B}{Y}$

To compare these two fractions without using floating-point arithmetic (which can lead to precision errors), we use **cross-multiplication**. 
Instead of comparing $\frac{A}{X}$ and $\frac{B}{Y}$, we compare $A \times Y$ and $B \times X$:
- If $A \times Y > B \times X$, then Alice is faster.
- If $A \times Y < B \times X$, then Bob is faster.
- If $A \times Y = B \times X$, then their speeds are equal.

Using `long long` ensures that the multiplication does not overflow, as the input constraints are well within the limits for 64-bit integers.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since there are $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Speed Limit Test
 * Speed = Distance / Time
 * Alice's speed = A / X
 * Bob's speed = B / Y
 * To compare A/X and B/Y without floating point precision issues,
 * we compare A * Y and B * X.
 * If A * Y > B * X, then Alice is faster.
 * If A * Y < B * X, then Bob is faster.
 * If A * Y == B * X, then they are equal.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, x, b, y;
        cin >> a >> x >> b >> y;

        // Using cross-multiplication to compare fractions A/X and B/Y
        // A/X vs B/Y  =>  A*Y vs B*X
        long long alice_val = a * y;
        long long bob_val = b * x;

        if (alice_val > bob_val) {
            cout << "ALICE" << "\n";
        } else if (bob_val > alice_val) {
            cout << "BOB" << "\n";
        } else {
            cout << "EQUAL" << "\n";
        }
    }

    return 0;
}
```