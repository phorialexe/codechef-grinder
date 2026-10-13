#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total days in semester = 120.
 * Required attendance = 75% of 120 = 0.75 * 120 = 90 days.
 * 
 * Chef has already attended 'present_count' days out of 'N' days.
 * Remaining days in the semester = 120 - N.
 * To maximize attendance, assume Chef attends all remaining days.
 * Total possible attendance = present_count + (120 - N).
 * 
 * Condition to pass: Total possible attendance >= 90.
 */

void solve() {
    int N;
    cin >> N;
    string B;
    cin >> B;

    int present_count = 0;
    for (char c : B) {
        if (c == '1') {
            present_count++;
        }
    }

    // Remaining days in the semester
    int remaining_days = 120 - N;
    
    // Maximum possible attendance if Chef attends all remaining days
    int max_possible_attendance = present_count + remaining_days;

    if (max_possible_attendance >= 90) {
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
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}