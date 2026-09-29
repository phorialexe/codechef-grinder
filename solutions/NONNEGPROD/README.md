# [Non-Negative Product (NONNEGPROD)](https://www.codechef.com/problems/NONNEGPROD)

- **Difficulty Rating**: 948
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, determine the minimum number of elements that must be removed so that the product of the remaining elements is non-negative (i.e., $\ge 0$).

## Intuition & Mathematical Observation
The product of a set of numbers is non-negative if:
1. **The product is zero**: This happens if at least one element in the array is $0$.
2. **The product is positive**: This happens if there are no zeros and the count of negative numbers is **even**.

If the product is currently negative (meaning there are no zeros and an odd number of negative integers), we can change the sign of the product to positive by removing exactly one negative number. This will make the count of negative numbers even.

**Logic:**
- If the array contains at least one `0`, the product is already $0$. We need to remove **0** elements.
- If the count of negative numbers is even, the product is already positive. We need to remove **0** elements.
- If the count of negative numbers is odd, the product is negative. We need to remove **1** element (any one of the negative numbers) to make the product positive.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to count zeros and negative numbers.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The product of an array is non-negative if:
 * 1. There is at least one zero in the array (product becomes 0).
 * 2. The number of negative integers is even.
 * 
 * If the product is negative (i.e., there are no zeros and the count of 
 * negative numbers is odd), we only need to remove one negative number 
 * to make the count of negative numbers even.
 */

void solve() {
    int N;
    cin >> N;
    
    int zero_count = 0;
    int negative_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a == 0) {
            zero_count++;
        } else if (a < 0) {
            negative_count++;
        }
    }
    
    // If there is at least one zero, the product is 0 (non-negative)
    if (zero_count > 0) {
        cout << 0 << "\n";
    } 
    // If the number of negative integers is even, the product is positive
    else if (negative_count % 2 == 0) {
        cout << 0 << "\n";
    } 
    // If the number of negative integers is odd, the product is negative
    // Removing one negative number makes the count even
    else {
        cout << 1 << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```