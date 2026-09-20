# [Ciel and Receipt (CIELRCPT)](https://www.codechef.com/problems/CIELRCPT)

- **Difficulty Rating**: 936
- **Solved in**: 1 attempt(s)

## Problem Summary
Tomya is at a restaurant where the menu prices are all powers of 2 ($2^0, 2^1, 2^2, \dots, 2^{11}$). Given a total bill amount $p$, we need to find the minimum number of menu items required to make the sum exactly $p$. Note that we can order the same menu item multiple times.

## Intuition & Mathematical Observation
The menu prices are $\{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048\}$. 

1. **Greedy Strategy**: To minimize the number of items, we should always pick the largest possible price that is less than or equal to the remaining amount.
2. **Handling 2048**: Since 2048 is the largest available price, we can use it as many times as possible by calculating `p / 2048`. This reduces the problem to representing the remainder ($p \pmod{2048}$) using the remaining powers of 2 ($2^0$ to $2^{10}$).
3. **Binary Representation**: Any integer can be uniquely represented as a sum of distinct powers of 2 (binary representation). The number of items needed for the remainder is simply the number of set bits (1s) in its binary form.
4. **Implementation**: We divide $p$ by 2048 to get the count of the largest item, then use the bitwise `__builtin_popcount()` function or a simple loop to count the set bits of the remainder.

## Complexity Analysis
- **Time Complexity**: $O(T \times \log(p))$, where $T$ is the number of test cases. Since $p \le 100,000$, $\log(p)$ is very small (at most 17 iterations), making this approach highly efficient.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The menu prices are powers of 2: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048.
 * To minimize the number of items, we use the largest price (2048) greedily,
 * then represent the remainder using the binary representation (sum of powers of 2).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int p;
        cin >> p;

        int count = 0;

        // Use the largest menu price (2048) as much as possible
        count += p / 2048;
        p %= 2048;

        // For the remainder, count the number of set bits (1s in binary representation)
        // This corresponds to the minimum number of items using powers of 2 from 1 to 1024
        while (p > 0) {
            if (p & 1) {
                count++;
            }
            p >>= 1;
        }

        cout << count << "\n";
    }

    return 0;
}
```