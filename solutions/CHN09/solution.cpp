#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Malvika wants all balloons to be the same color.
 * There are only two colors: 'a' (amber) and 'b' (brass).
 * To make all balloons 'a', we must paint all 'b' balloons to 'a'.
 * The number of operations required would be the count of 'b's.
 * To make all balloons 'b', we must paint all 'a' balloons to 'b'.
 * The number of operations required would be the count of 'a's.
 * To minimize the operations, we take the minimum of (count of 'a's, count of 'b's).
 * 
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string, or O(1) if processed character by character.
 */

void solve() {
    string s;
    cin >> s;
    
    int count_a = 0;
    int count_b = 0;
    
    for (char c : s) {
        if (c == 'a') {
            count_a++;
        } else if (c == 'b') {
            count_b++;
        }
    }
    
    // The minimum flips required is the minimum of the two counts
    cout << min(count_a, count_b) << "\n";
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