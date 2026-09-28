# [Make A and B equal (EQUALISE)](https://www.codechef.com/problems/EQUALISE)

- **Difficulty Rating**: 851
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, we are allowed to multiply either number by 2 as many times as we want. The goal is to determine if it is possible to make $A$ and $B$ equal through these operations.

## Intuition & Mathematical Observation
The problem asks if there exist non-negative integers $x$ and $y$ such that:
$$A \times 2^x = B \times 2^y$$

This can be rearranged as:
$$\frac{A}{B} = 2^{y-x}$$

Essentially, one number must be a power-of-two multiple of the other. To solve this:
1. Identify the smaller number and the larger number.
2. Repeatedly multiply the smaller number by 2.
3. If at any point the smaller number becomes equal to the larger number, the answer is **YES**.
4. If the smaller number exceeds the larger number without ever being equal to it, the answer is **NO**.

## Complexity Analysis
- **Time Complexity**: $O(\log(\frac{\max(A, B)}{\min(A, B)}))$ per test case. Since the numbers are multiplied by 2 in each step, the loop runs at most logarithmic times relative to the difference between the two numbers.
- **Space Complexity**: $O(1)$, as we only use a few variables for storage.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two numbers A and B. We can multiply either by 2 any number of times.
 * This means we can transform A into A * 2^x and B into B * 2^y.
 * We want to check if there exist non-negative integers x, y such that A * 2^x = B * 2^y.
 * 
 * Algorithm:
 * 1. Ensure A <= B by swapping if necessary.
 * 2. While A < B, multiply A by 2.
 * 3. If A becomes equal to B, output YES, otherwise output NO.
 */

void solve() {
    int A, B;
    cin >> A >> B;
    
    // Ensure A is the smaller number
    if (A > B) {
        swap(A, B);
    }
    
    // Keep doubling the smaller number until it reaches or exceeds the larger
    while (A < B) {
        A *= 2;
    }
    
    if (A == B) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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