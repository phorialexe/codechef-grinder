#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A week has 7 days. Akash takes a leave every Saturday.
 * The month starts on a Monday.
 * The sequence of days is:
 * Day 1: Monday
 * Day 2: Tuesday
 * Day 3: Wednesday
 * Day 4: Thursday
 * Day 5: Friday
 * Day 6: Saturday (Leave)
 * Day 7: Sunday
 * 
 * Every 7 days, there is exactly one Saturday.
 * For a month of N days, the number of full weeks is N / 7.
 * Each full week contributes 1 Saturday.
 * The remaining days are N % 7.
 * If the remaining days are 6 or more, there is an additional Saturday.
 * 
 * Formula: (N / 7) + ((N % 7 == 6) ? 1 : 0)
 */

int main() {
    // Optimize I/O operations
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
        // If N % 7 is 6, we have exactly one extra Saturday.
        if (n % 7 == 6) {
            leaves += 1;
        }
        
        cout << leaves << "\n";
    }
    
    return 0;
}