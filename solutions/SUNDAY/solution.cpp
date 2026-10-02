#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The month has 30 days.
 * Day 1 is Monday.
 * Days follow a 7-day cycle:
 * Monday: 1, 8, 15, 22, 29
 * Tuesday: 2, 9, 16, 23, 30
 * Wednesday: 3, 10, 17, 24
 * Thursday: 4, 11, 18, 25
 * Friday: 5, 12, 19, 26
 * Saturday: 6, 13, 20, 27
 * Sunday: 7, 14, 21, 28
 * 
 * Holidays are Saturdays (6, 13, 20, 27), Sundays (7, 14, 21, 28),
 * and the given N festival days.
 * To avoid double counting, we use a boolean array or a set to mark all holidays.
 */

void solve() {
    int n;
    cin >> n;
    
    // Using a boolean array to track if a day is a holiday
    vector<bool> is_holiday(31, false);
    
    // Mark Saturdays and Sundays
    // Saturdays: 6, 13, 20, 27
    // Sundays: 7, 14, 21, 28
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