#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: CUTESTR
 * A string S of length 3 is cute if:
 * 1. S[0] == S[2]
 * 2. S[1] == 'w'
 * 
 * Time Complexity: O(1) per test case
 * Space Complexity: O(1)
 */

void solve() {
    string s;
    cin >> s;
    
    // Check if the string length is 3 (guaranteed by constraints)
    // Check if the first and third characters are equal
    // Check if the middle character is 'w'
    if (s.length() == 3 && s[0] == s[2] && s[1] == 'w') {
        cout << "Cute" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single string input, 
    // but standard competitive programming practice often involves 
    // test cases. Given the problem format, we handle the single input.
    solve();

    return 0;
}