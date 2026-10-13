# [Chef and Steps (CHEFSTEP)](https://www.codechef.com/problems/CHEFSTEP)

- **Difficulty Rating**: 1110
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef has $N$ distances $D_1, D_2, \dots, D_N$ he wants to walk. He can only take steps of a fixed length $K$. For each distance $D_i$, determine if it is possible for Chef to cover the exact distance using only steps of length $K$. Output '1' if possible, and '0' otherwise.

## Intuition & Mathematical Observation
A distance $D_i$ can be covered exactly by steps of length $K$ if and only if $D_i$ is perfectly divisible by $K$. 
- If $D_i \pmod K = 0$, Chef can take exactly $D_i / K$ steps to reach the destination.
- If $D_i \pmod K \neq 0$, there will always be a remainder, making it impossible to cover the distance exactly.

Since the constraints allow $D_i$ and $K$ to be as large as $10^9$, we must use the `long long` data type in C++ to prevent overflow during input, although the modulo operation itself is safe with standard integers if the values are within range.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. Given $T$ test cases, the total time complexity is $O(T \times N)$. With $T, N \le 1000$, the total operations are roughly $10^6$, which easily passes within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we process each distance on the fly without storing the entire array.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Chef can only walk in steps of length K.
 * A distance D_i is traversable if D_i is a multiple of K.
 * Mathematically: D_i % K == 0.
 * 
 * Constraints:
 * T <= 1000, N <= 1000. Total operations ~ 10^6, which fits in 1s.
 * D_i and K can be up to 10^9, so use long long for calculations.
 */

void solve() {
    int n;
    long long k;
    if (!(cin >> n >> k)) return;
    
    for (int i = 0; i < n; ++i) {
        long long d;
        cin >> d;
        // Check if the distance is perfectly divisible by step size K
        if (d % k == 0) {
            cout << '1';
        } else {
            cout << '0';
        }
    }
    cout << "\n";
}

int main() {
    // Fast I/O setup for performance
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