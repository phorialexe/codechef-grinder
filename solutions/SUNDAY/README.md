# [Count the Holidays (SUNDAY)](https://www.codechef.com/problems/SUNDAY)

- **Difficulty Rating**: 907
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total number of holidays in a 30-day month. A day is considered a holiday if it is either a weekend (Saturday or Sunday) or a specific festival day provided in the input. We are given that the 1st of the month is a Monday.

## Intuition & Mathematical Observation
Since the month has a fixed length of 30 days and the starting day is fixed (Monday), the dates for Saturdays and Sundays are constant:
- **Saturdays**: 6, 13, 20, 27
- **Sundays**: 7, 14, 21, 28

There are exactly 8 weekend days. To calculate the total holidays, we must count these 8 days plus any festival days provided. The key challenge is to **avoid double-counting** if a festival falls on a weekend. 

Using a boolean array of size 31 (to represent days 1–30) allows us to mark holidays efficiently. By setting `is_holiday[day] = true` for all weekends and festival days, we ensure that each day is counted at most once, regardless of whether it is both a weekend and a festival.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of festival days. Since the month length is constant (30 days), the loop to count the holidays runs in $O(1)$ time. Overall, the complexity is $O(N)$.
- **Space Complexity**: $O(1)$, as we use a fixed-size boolean array of size 31 regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The month has 30 days.
 * Day 1 is Monday.
 * Days follow a 7-day cycle:
 * Saturdays: 6, 13, 20, 27
 * Sundays: 7, 14, 21, 28
 * 
 * Holidays are Saturdays, Sundays, and the given N festival days.
 * We use a boolean array to mark all unique holidays to avoid double counting.
 */

void solve() {
    int n;
    cin >> n;
    
    // Using a boolean array to track if a day is a holiday
    vector<bool> is_holiday(31, false);
    
    // Mark Saturdays and Sundays
    int weekends[] = {6, 13, 20, 27, 7, 14, 21, 28};
    for (int day : weekends) {
        is_holiday[day] = true;
    }
    
    // Mark festival days
    for (int i = 0; i < n; ++i) {
        int festival_day;
        cin >> festival_day;
        is_holiday[festival_day] = true;
    }
    
    // Count total holidays
    int total_holidays = 0;
    for (int i = 1; i <= 30; ++i) {
        if (is_holiday[i]) {
            total_holidays++;
        }
    }
    
    cout << total_holidays << "\n";
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