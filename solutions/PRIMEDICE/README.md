# [Hackerman (PRIMEDICE)](https://www.codechef.com/problems/PRIMEDICE)

- **Difficulty Rating**: 643
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob are playing a game involving two dice. Alice rolls a die with value $A$, and Bob rolls a die with value $B$, where $1 \le A, B \le 6$. The sum of the two dice is $S = A + B$. Alice wins if the sum $S$ is a prime number; otherwise, Bob wins. Given $A$ and $B$, determine the winner.

## Intuition & Mathematical Observation
1. **Range of Sum**: Since $1 \le A, B \le 6$, the sum $S = A + B$ will always fall in the range $[2, 12]$.
2. **Prime Identification**: We need to identify which numbers in the range $[2, 12]$ are prime.
   - The prime numbers in this range are: **2, 3, 5, 7, and 11**.
3. **Logic**: For every test case, calculate the sum $A + B$ and check if it belongs to the set $\{2, 3, 5, 7, 11\}$. If it does, output "Alice"; otherwise, output "Bob".

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Since the check for primality is performed on a constant range (up to 12), the operation per test case is $O(1)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob roll dice with values A and B (1 <= A, B <= 6).
 * The sum S = A + B ranges from 2 to 12.
 * Alice wins if S is prime.
 * Prime numbers in the range [2, 12] are: 2, 3, 5, 7, 11.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1).
 */

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int sum = a + b;
        
        if (is_prime(sum)) {
            cout << "Alice" << "\n";
        } else {
            cout << "Bob" << "\n";
        }
    }
    
    return 0;
}
```