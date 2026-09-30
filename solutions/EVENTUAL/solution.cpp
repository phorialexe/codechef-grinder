#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to remove a substring if every character in that substring 
 * appears an even number of times. 
 * 
 * Key Insight:
 * If we can erase the entire string, it implies that every character in the original 
 * string must appear an even number of times. 
 * 
 * Proof Sketch:
 * 1. If every character appears an even number of times, we can always erase the 
 *    entire string. In the simplest case, we can just pick the whole string as the 
 *    substring to erase (since the whole string satisfies the condition).
 * 2. If any character appears an odd number of times, it is impossible to erase 
 *    the entire string. Each operation removes an even count of each character 
 *    present in the substring. If we start with an odd count of a character, 
 *    subtracting even counts will always leave an odd count remaining. Since we 
 *    need to reach a count of 0 (which is even), we can never eliminate a character 
 *    that starts with an odd frequency.
 * 
 * Therefore, the condition is simply: check if the frequency of every character 
 * in the string is even.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // If the length is odd, it's impossible for all characters to have even counts.
    if (n % 2 != 0) {
        cout << "NO" << "\n";
        return;
    }

    // Count frequencies of each character
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Check if all frequencies are even
    bool possible = true;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] % 2 != 0) {
            possible = false;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}