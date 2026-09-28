#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Encoding Message
 * Approach:
 * 1. Step 1: Swap adjacent characters in pairs (0,1), (2,3), etc.
 *    If N is odd, the last character remains untouched.
 * 2. Step 2: Replace each character 'c' with its mirror in the alphabet.
 *    The mirror of 'a' (0) is 'z' (25), 'b' (1) is 'y' (24), etc.
 *    Formula: new_char = 'z' - (old_char - 'a')
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // Step 1: Swap adjacent characters
    for (int i = 0; i + 1 < n; i += 2) {
        swap(s[i], s[i + 1]);
    }

    // Step 2: Replace characters
    // 'a' -> 'z', 'b' -> 'y', ..., 'z' -> 'a'
    // Mathematically: new_char = 'a' + ('z' - old_char)
    for (int i = 0; i < n; ++i) {
        s[i] = 'a' + ('z' - s[i]);
    }

    cout << s << "\n";
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