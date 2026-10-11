# [Akash and Missing Class (CHFCLASS)](https://www.codechef.com/problems/CHFCLASS)

- **Difficulty Rating**: 931
- **Solved in**: 1 attempt(s)

## Problem Summary
Akash takes a leave every Saturday. Given that a month starts on a Monday, we need to determine how many Saturdays occur in a month consisting of $N$ days. Since a week consists of 7 days (Monday through Sunday), the 6th day of every week is a Saturday.

## Intuition & Mathematical Observation
The problem asks us to count how many times the 6th day occurs within a sequence of $N$ days.

1. **Full Weeks**: Every 7 days, there is exactly one Saturday. We can calculate the number of full weeks using integer division: `N / 7`. This gives us the base count of Saturdays.
2. **Remaining Days**: After accounting for full weeks, there are `N % 7` days left. 
   - The sequence of days in a week is: 1 (Mon), 2 (Tue), 3 (Wed), 4 (Thu), 5 (Fri), 6 (Sat), 7 (Sun).
   - If the remainder is 6, it means the sequence reached the 6th day (Saturday).
   - Therefore, if `N % 7 == 6`, we must add one additional Saturday to our total.

**Formula**: 
$$\text{Total Saturdays} = \lfloor N / 7 \rfloor + (1 \text{ if } N \pmod 7 == 6 \text{ else } 0)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we only perform basic arithmetic operations (division and modulo), the calculation is instantaneous regardless of the size of $N$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A week has 7 days. Akash takes a leave every Saturday.
 * The month starts on a Monday.
 * 
 * Every 7 days, there is exactly one Saturday.
 * For a month of N days, the number of full weeks is N / 7.
 * Each full week contributes 1 Saturday.
 * The remaining days are N % 7.
 * If the remaining days are 6, there is an additional Saturday.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Calculate number of full weeks
        long long leaves = n / 7;
        
        // Check if the remaining days include a Saturday
        // Since the month starts on Monday, the 6th day is Saturday.
        if (n % 7 == 6) {
            leaves += 1;
        }
        
        cout << leaves << "\n";
    }
    
    return 0;
}
```