#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: GOODWEAT
 * Logic:
 * We are given 7 integers representing days (1 for sunny, 0 for rainy).
 * A week is "Good" if the count of 1s > count of 0s.
 * Since there are 7 days total, count of 0s = 7 - count of 1s.
 * Condition: count of 1s > 7 - count of 1s
 * => 2 * count of 1s > 7
 * => count of 1s >= 4
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int sunny_days = 0;
        for (int i = 0; i < 7; ++i) {
            int day;
            cin >> day;
            if (day == 1) {
                sunny_days++;
            }
        }
        
        // Total days = 7. Rainy days = 7 - sunny_days.
        // Good if sunny_days > rainy_days
        // sunny_days > 7 - sunny_days
        // 2 * sunny_days > 7
        if (sunny_days > 3) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}