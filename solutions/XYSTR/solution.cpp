#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string of 'x's and 'y's. We want to form the maximum number of 
 * adjacent pairs (boy, girl). Since each student can be in at most one pair, 
 * this is a classic greedy problem.
 * 
 * Strategy:
 * Iterate through the string from left to right. If the current student and the 
 * next student form a pair (one is 'x' and the other is 'y'), we pair them up 
 * and skip the next student (increment index by 2). Otherwise, move to the 
 * next student (increment index by 1).
 * 
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int pairs = 0;
    
    for (int i = 0; i < n - 1; ) {
        // Check if current student and next student are different
        if (s[i] != s[i + 1]) {
            pairs++;
            // Move index by 2 because both students are now paired
            i += 2;
        } else {
            // Move index by 1 to check the next possible pair
            i++;
        }
    }
    
    cout << pairs << "\n";
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