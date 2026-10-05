#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length 4.
 * An echo is defined as S[0] == S[2] and S[1] == S[3] (using 0-indexing).
 * The constraints are small (length 4), so a simple comparison is O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    // Check the echo condition:
    // S[0] is the 1st character, S[2] is the 3rd character.
    // S[1] is the 2nd character, S[3] is the 4th character.
    if (s[0] == s[2] && s[1] == s[3]) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}