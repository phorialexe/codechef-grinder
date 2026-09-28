# [Binary Parity (BINPARITY)](https://www.codechef.com/problems/BINPARITY)

- **Difficulty Rating**: 771
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to determine the parity of the sum of its binary digits. Specifically, we count the number of set bits (1s) in the binary representation of $N$. If the total count of set bits is even, output "EVEN"; otherwise, output "ODD".

## Intuition & Mathematical Observation
The problem asks for the parity of the population count (number of set bits) of a given integer $N$. 
- In binary representation, the sum of digits is simply the count of bits that are equal to 1.
- For any integer $N \le 10^9$, the number of bits is small (at most 30 bits).
- We can efficiently calculate the number of set bits using the built-in C++ function `__builtin_popcount(n)`.
- Once we have the count, we use the modulo operator (`% 2`) to check if the count is even or odd.

## Complexity Analysis
- **Time Complexity**: $O(T \times \log N)$, where $T$ is the number of test cases. The `__builtin_popcount` function typically runs in $O(1)$ or $O(\text{number of bits})$ time, which is effectively constant for a 32-bit integer.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the bit count.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks for the parity of the sum of binary digits of N.
 * This is equivalent to finding the population count (number of set bits) of N.
 * If the number of set bits is even, output "EVEN".
 * If the number of set bits is odd, output "ODD".
 * 
 * C++ provides a built-in function __builtin_popcount(n) which returns the 
 * number of set bits in an integer. Since N <= 10^9, it fits in a 32-bit 
 * integer, so __builtin_popcount is sufficient.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        // __builtin_popcount returns the number of 1s in the binary representation
        int set_bits = __builtin_popcount(n);
        
        // Check if the count is even or odd
        if (set_bits % 2 == 0) {
            cout << "EVEN" << "\n";
        } else {
            cout << "ODD" << "\n";
        }
    }
    
    return 0;
}
```