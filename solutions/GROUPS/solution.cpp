#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A group is defined as a contiguous sequence of '1's.
 * We need to count how many such sequences exist in the string S.
 * 
 * Logic:
 * A new group starts whenever we encounter a '1' that is either at the 
 * beginning of the string or is preceded by a '0'.
 * 
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    string s;
    cin >> s;
    
    int groups = 0;
    int n = s.length();
    
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            // If this is the start of a group:
            // It's the start if it's the first character or the previous was '0'
            if (i == 0 || s[i - 1] == '0') {
                groups++;
            }
        }
    }
    
    cout << groups << "\n";
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