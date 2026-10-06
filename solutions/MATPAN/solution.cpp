#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given the prices of all 26 lowercase English letters.
 * We are given a string that might be missing some letters.
 * To make the string a pangram, we must purchase the missing letters.
 * Since we want the cheapest way, we simply identify which letters are 
 * not present in the input string and sum their corresponding prices.
 * 
 * Constraints:
 * T <= 10
 * N <= 50,000
 * Prices <= 1,000,000
 * Total cost can exceed 2^31 - 1, so use long long for the sum.
 * Time complexity: O(T * (N + 26)), which is well within the 1s limit.
 */

void solve() {
    vector<long long> prices(26);
    for (int i = 0; i < 26; ++i) {
        cin >> prices[i];
    }

    string s;
    cin >> s;

    // Track which letters are present
    vector<bool> present(26, false);
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            present[c - 'a'] = true;
        }
    }

    // Calculate total cost for missing letters
    long long total_cost = 0;
    for (int i = 0; i < 26; ++i) {
        if (!present[i]) {
            total_cost += prices[i];
        }
    }

    cout << total_cost << "\n";
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