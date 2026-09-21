#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We need to ensure no two consecutive characters are the same.
 * Whenever we find S[i] == S[i+1], we must perform an insertion.
 * Inserting a character between S[i] and S[i+1] breaks the conflict.
 * We iterate through the string and count how many times S[i] == S[i+1].
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int operations = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1]) {
            operations++;
        }
    }
    cout << operations << "\n";
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