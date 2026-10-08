# [Am I Lucky! (SPCP4)](https://www.codechef.com/problems/SPCP4)

- **Difficulty Rating**: 941
- **Solved in**: 1 attempt(s)

## Problem Summary
In a class of $N$ students, there are $X$ boys and $N-X$ girls. The students are divided into groups of size $K$. Any students who cannot form a full group of size $K$ are left over. Among these leftover students, boys and girls pair up to dance. Each pair consists of one boy and one girl. Any leftover students who cannot form a pair must read. We need to find the number of students who end up reading.

## Intuition & Mathematical Observation
1. **Group Formation**: When dividing $X$ boys into groups of size $K$, the number of boys remaining is `remB = X % K`. Similarly, for $N-X$ girls, the number of girls remaining is `remG = (N - X) % K`.
2. **Pairing**: Since each dancing pair requires one boy and one girl, the number of pairs that can be formed is `min(remB, remG)`.
3. **Reading**: The total number of leftover students is `remB + remG`. Since `2 * min(remB, remG)` students are dancing, the number of students left to read is:
   $$(remB + remG) - 2 \times \min(remB, remG)$$
4. **Simplification**: This expression is mathematically equivalent to the absolute difference between the two remainders:
   $$|remB - remG|$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total students = N
 * Boys = X
 * Girls = N - X
 * Group size = K
 * 
 * Boys form groups: X / K groups, remainder boys = X % K
 * Girls form groups: (N - X) / K groups, remainder girls = (N - X) % K
 * 
 * Let remB = X % K
 * Let remG = (N - X) % K
 * 
 * Dancing requires one boy and one girl.
 * The number of pairs that can be formed is min(remB, remG).
 * The number of students left over (who must read) is:
 * Total remaining = remB + remG
 * Students dancing = 2 * min(remB, remG)
 * Students reading = (remB + remG) - 2 * min(remB, remG)
 * 
 * This simplifies to the absolute difference: |remB - remG|
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, k;
        cin >> n >> x >> k;

        long long boys = x;
        long long girls = n - x;

        long long remB = boys % k;
        long long remG = girls % k;

        // The number of students reading is the absolute difference 
        // between the remaining boys and remaining girls.
        long long reading = abs(remB - remG);

        cout << reading << "\n";
    }

    return 0;
}
```