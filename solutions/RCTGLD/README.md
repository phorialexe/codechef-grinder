# [Rectangled (RCTGLD)](https://www.codechef.com/problems/RCTGLD)

- **Difficulty Rating**: 751
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ units of ink, we need to form a rectangle with integer side lengths $a$ and $b$ such that the perimeter $P = 2(a + b)$ does not exceed $N$. The goal is to maximize the area $A = a \times b$ of the rectangle. If no such rectangle can be formed (i.e., $N < 4$), the area is considered 0.

## Intuition & Mathematical Observation
1. **Perimeter Constraint**: The condition $2(a + b) \le N$ simplifies to $a + b \le \lfloor N/2 \rfloor$. Let $S = \lfloor N/2 \rfloor$.
2. **Maximizing Area**: We want to maximize the product $a \times b$ given that their sum $a + b \le S$. To maximize the product of two numbers with a fixed sum, the numbers should be as close to each other as possible.
3. **Optimal Values**:
   - If $S$ is even, the optimal sides are $a = S/2$ and $b = S/2$.
   - If $S$ is odd, the optimal sides are $a = \lfloor S/2 \rfloor$ and $b = \lceil S/2 \rceil$.
4. **Edge Case**: Since the sides must be positive integers, the smallest possible perimeter is $2(1+1) = 4$. If $N < 4$, it is impossible to form a rectangle, so the area is 0.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated area.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A rectangle with sides 'a' and 'b' (where a, b are integers) has a perimeter 
 * P = 2 * (a + b).
 * The problem states we have N units of ink, so 2 * (a + b) <= N.
 * This simplifies to a + b <= N / 2.
 * Since a and b must be integers, a + b <= floor(N / 2).
 * Let S = floor(N / 2). We want to maximize area A = a * b subject to a + b <= S.
 * To maximize the product of two numbers with a fixed sum, the numbers should be 
 * as close to each other as possible.
 */

void solve() {
    int N;
    cin >> N;
    
    // Minimum perimeter for a rectangle with integer sides 1x1 is 4.
    if (N < 4) {
        cout << 0 << "\n";
        return;
    }
    
    int S = N / 2;
    int a = S / 2;
    int b = S - a;
    
    long long area = (long long)a * b;
    cout << area << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```