#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: DNASTRAND
 * The task is to replace each character in the DNA string with its complement:
 * A <-> T
 * C <-> G
 * 
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string result = "";
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            result += 'T';
        } else if (s[i] == 'T') {
            result += 'A';
        } else if (s[i] == 'C') {
            result += 'G';
        } else if (s[i] == 'G') {
            result += 'C';
        }
    }
    cout << result << "\n";
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