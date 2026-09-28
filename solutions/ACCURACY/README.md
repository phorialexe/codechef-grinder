# [High Accuracy (ACCURACY)](https://www.codechef.com/problems/ACCURACY)

- **Difficulty Rating**: 580
- **Solved in**: 1 attempt(s)

## Problem Summary
In a test with 100 questions, each correct answer awards 3 marks, and each wrong answer deducts 1 mark. Given a total score $X$, we need to find the minimum number of wrong answers required to achieve exactly $X$ marks.

## Intuition & Mathematical Observation
Let $C$ be the number of correct answers and $W$ be the number of wrong answers. The total score is given by the equation:
$$X = 3C - W$$

We want to minimize $W$ such that $3C - W = X$. Rearranging for $W$, we get:
$$W = 3C - X$$

Since $W$ must be a non-negative integer, $3C$ must be the smallest multiple of 3 that is greater than or equal to $X$. This means $W$ is essentially the "distance" to the next multiple of 3:

1. If $X$ is a multiple of 3 ($X \pmod 3 = 0$), then $W = 0$.
2. If $X \pmod 3 = 1$, the next multiple of 3 is $X+2$. Thus, $W = 2$.
3. If $X \pmod 3 = 2$, the next multiple of 3 is $X+1$. Thus, $W = 1$.

This can be summarized as:
- If $X \% 3 == 0 \implies 0$
- If $X \% 3 == 1 \implies 2$
- If $X \% 3 == 2 \implies 1$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the minimum wrong answers (W) such that 3*C - W = X.
 * This is equivalent to finding the smallest non-negative W such that 
 * (X + W) is divisible by 3.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the remainder when divided by 3
        int rem = x % 3;
        
        // If x is divisible by 3, remainder is 0, so 0 wrong answers needed.
        // If remainder is 1, we need 2 wrong answers to reach the next multiple of 3.
        // If remainder is 2, we need 1 wrong answer to reach the next multiple of 3.
        if (rem == 0) {
            cout << 0 << "\n";
        } else if (rem == 1) {
            cout << 2 << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
    
    return 0;
}
```