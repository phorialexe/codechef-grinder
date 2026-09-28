# [Chef and SnackDown (SNCKYEAR)](https://www.codechef.com/problems/SNCKYEAR)

- **Difficulty Rating**: 895
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine whether the "SnackDown" programming contest was hosted in a given year $N$. We are provided with a specific list of years in which the event took place: 2010, 2015, 2016, 2017, and 2019. For any input year $N$ (where $2010 \le N \le 2019$), we must output "HOSTED" if the year is in the list, and "NOT HOSTED" otherwise.

## Intuition & Mathematical Observation
Since the set of years is small and finite, we do not need complex algorithms or data structures. The most efficient approach is to perform a direct comparison. 

By checking the input year $N$ against the known set $\{2010, 2015, 2016, 2017, 2019\}$, we can immediately determine the status. Using a simple `if-else` conditional statement or a `switch` case provides $O(1)$ lookup time, which is optimal for this problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we are performing a constant number of comparisons regardless of the input value, the time complexity remains constant.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the input, requiring no additional memory that scales with input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and SnackDown
 * The years SnackDown was hosted are: 2010, 2015, 2016, 2017, 2019.
 * We can store these in a set or use a simple conditional check.
 * Given the constraints (2010 <= N <= 2019), a simple check is efficient.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n;
        cin >> n;

        // Check if the year is one of the hosted years
        if (n == 2010 || n == 2015 || n == 2016 || n == 2017 || n == 2019) {
            cout << "HOSTED" << "\n";
        } else {
            cout << "NOT HOSTED" << "\n";
        }
    }

    return 0;
}
```