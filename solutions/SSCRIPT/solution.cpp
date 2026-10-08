#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Strong Language
 * Approach:
 * We need to find if there exists a substring of '*' with length at least K.
 * We can iterate through the string and maintain a counter for consecutive '*'.
 * If the counter reaches K, we immediately know the answer is "YES".
 * If we encounter a character that is not '*', we reset the counter to 0.
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int current_consecutive = 0;
    bool found = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '*') {
            current_consecutive++;
            if (current_consecutive >= K) {
                found = true;
                break;
            }
        } else {
            current_consecutive = 0;
        }
    }

    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}