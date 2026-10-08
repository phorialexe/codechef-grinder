#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob take turns picking characters from string S.
 * Since they take turns, Alice will pick N/2 characters and Bob will pick N/2 characters.
 * For their final strings A and B to be identical, they must have picked the same 
 * multiset of characters.
 * 
 * This means for every character 'a' through 'z', the total count of that character 
 * in the original string S must be even. If any character appears an odd number 
 * of times, it is impossible to distribute them equally between Alice and Bob.
 * 
 * If all character counts are even, we can always construct the strings such that 
 * they are identical. For example, if we have two 'x's, Alice can take one and 
 * Bob can take one. By alternating turns, we can ensure they both end up with 
 * the same multiset of characters.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // If the length is odd, it's impossible to split into two equal strings
    if (n % 2 != 0) {
        cout << "NO" << "\n";
        return;
    }

    // Count frequency of each character
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Check if every character appears an even number of times
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