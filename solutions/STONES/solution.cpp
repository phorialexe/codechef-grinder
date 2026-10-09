#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two strings: J (jewels) and S (stones).
 * We need to count how many characters in S are present in J.
 * 
 * Constraints:
 * T test cases.
 * Length of J and S <= 100.
 * Characters are English letters (a-z, A-Z).
 * 
 * Approach:
 * Since the character set is small (ASCII), we can use a boolean array or a hash set
 * to store the characters present in J for O(1) lookup.
 * Then iterate through S and check if each character exists in the set.
 * Total time complexity: O(T * (|J| + |S|)), which is well within the 0.5s limit.
 */

void solve() {
    string J, S;
    cin >> J >> S;

    // Use a boolean array to mark characters present in J.
    // ASCII range is 0-127, size 128 is sufficient.
    bool is_jewel[128] = {false};

    for (char c : J) {
        is_jewel[(int)c] = true;
    }

    long long count = 0;
    for (char c : S) {
        if (is_jewel[(int)c]) {
            count++;
        }
    }

    cout << count << "\n";
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