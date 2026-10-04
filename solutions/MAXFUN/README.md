# [Maximise Function (MAXFUN)](https://www.codechef.com/problems/MAXFUN)

- **Difficulty Rating**: 1301
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to choose three indices $x, y, z$ (not necessarily distinct) such that the value $|A_x - A_y| + |A_y - A_z| + |A_z - A_x|$ is maximized.

## Intuition & Mathematical Observation
Let the three chosen values be $a, b,$ and $c$ such that $a \le b \le c$. The expression $|A_x - A_y| + |A_y - A_z| + |A_z - A_x|$ can be rewritten based on the sorted order:
$$(b - a) + (c - b) + (c - a)$$
Simplifying this:
$$b - a + c - b + c - a = 2c - 2a = 2(c - a)$$

To maximize $2(c - a)$, we must choose the largest possible value in the array for $c$ and the smallest possible value in the array for $a$. The value of $b$ does not affect the final result as long as $a \le b \le c$, which is always satisfied if we pick the global minimum and global maximum of the array.

Thus, the maximum value is simply $2 \times (\max(A) - \min(A))$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to find the minimum and maximum values.
- **Space Complexity**: $O(1)$ auxiliary space (if we process elements on the fly) or $O(N)$ if we store the array. The provided solution uses $O(N)$ to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize |Ax - Ay| + |Ay - Az| + |Az - Ax|.
 * Let the sorted values of the chosen triple be a <= b <= c.
 * The expression becomes (b - a) + (c - b) + (c - a) = 2c - 2a = 2(c - a).
 * To maximize this, we need to pick the smallest possible value in the array
 * as 'a' and the largest possible value in the array as 'c'.
 * The middle value 'b' can be any other element in the array.
 * Since N >= 3, we can always pick the minimum element, the maximum element,
 * and any third element.
 * The maximum value is 2 * (max_element - min_element).
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long min_val = 2e9; // Larger than any possible A_i
    long long max_val = -2e9; // Smaller than any possible A_i

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < min_val) min_val = a[i];
        if (a[i] > max_val) max_val = a[i];
    }

    // The expression simplifies to 2 * (max - min)
    // Proof: Let the chosen values be x, y, z.
    // If we pick min, max, and any other element, the expression is:
    // |max - min| + |min - other| + |other - max|
    // Since max >= other >= min:
    // (max - min) + (other - min) + (max - other)
    // = max - min + other - min + max - other
    // = 2 * max - 2 * min = 2 * (max - min)
    
    long long result = 2 * (max_val - min_val);
    cout << result << "\n";
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