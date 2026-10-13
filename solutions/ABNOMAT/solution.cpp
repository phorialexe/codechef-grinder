#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice is happy if the name shares no characters with S_B.
 * Bob is happy if the name shares no characters with S_A.
 * We need to find if there exists a character 'c' (or a string of characters)
 * such that 'c' is not in S_A AND 'c' is not in S_B.
 * 
 * If there exists any character 'c' in the alphabet {'a'...'z'} that is 
 * not present in S_A and not present in S_B, then we can name the algorithm 
 * using that character (e.g., "c"), and both Alice and Bob will be happy.
 * 
 * Algorithm:
 * 1. Create a frequency array or boolean set for characters present in S_A.
 * 2. Create a frequency array or boolean set for characters present in S_B.
 * 3. Iterate through all characters 'a' through 'z'.
 * 4. If a character is not in S_A and not in S_B, output "YES".
 * 5. If no such character is found after checking all 26, output "NO".
 */

void solve() {
    int N, M;
    cin >> N >> M;
    string SA, SB;
    cin >> SA >> SB;

    vector<bool> in_SA(26, false);
    vector<bool> in_SB(26, false);

    for (char c : SA) {
        in_SA[c - 'a'] = true;
    }
    for (char c : SB) {
        in_SB[c - 'a'] = true;
    }

    bool found = false;
    for (int i = 0; i < 26; ++i) {
        if (!in_SA[i] && !in_SB[i]) {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}