#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to transform string S into "ADVITIYA".
 * For each character S[i], we can increment it cyclically (A->B, ..., Z->A).
 * The number of steps to change character 'c1' to 'c2' is:
 * (c2 - c1 + 26) % 26.
 * Since the string length is fixed at 8, we iterate through each index 
 * and sum the steps required for each character.
 */

void solve() {
    string S;
    cin >> S;
    string target = "ADVITIYA";
    long long total_steps = 0;

    for (int i = 0; i < 8; ++i) {
        int diff = (target[i] - S[i] + 26) % 26;
        total_steps += diff;
    }

    cout << total_steps << "\n";
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