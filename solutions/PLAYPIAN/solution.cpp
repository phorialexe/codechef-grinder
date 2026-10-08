#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The log records the piano sessions for multiple days.
 * Each day, both A and B play exactly once.
 * This means every 2 characters in the string represent one day.
 * For each pair (s[2*i], s[2*i+1]), one must be 'A' and the other must be 'B'.
 * If any pair consists of two identical characters (e.g., "AA" or "BB"), 
 * the log is invalid.
 */

void solve() {
    string s;
    cin >> s;
    
    bool possible = true;
    int n = s.length();
    
    // Iterate through the string in steps of 2
    for (int i = 0; i < n; i += 2) {
        // Check if the two characters in the current day are different
        if (s[i] == s[i + 1]) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}