#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string S of length N. We can rearrange the characters.
 * We want to know if we can make the first and last characters equal.
 * 
 * If we have at least two occurrences of any character 'c', we can place one 'c' 
 * at the start and one 'c' at the end. The remaining N-2 characters can be 
 * placed in between in any order.
 * 
 * Therefore, the condition is simply: Does the string contain at least one 
 * character that appears 2 or more times?
 * 
 * If N >= 2, we just need to check if any character frequency is >= 2.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    // Count frequencies of each character
    vector<int> freq(26, 0);
    for (char c : S) {
        freq[c - 'a']++;
    }

    // Check if any character appears at least twice
    bool possible = false;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] >= 2) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}