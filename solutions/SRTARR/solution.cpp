#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to sort a binary string (all 0s followed by all 1s) using the minimum number of reversals.
 * A sorted string looks like 00...0011...11.
 * 
 * Consider the transitions from '1' to '0' in the string.
 * Every time we have a substring "10", it represents an inversion.
 * If we have a block of 1s followed by a block of 0s, we can reverse that specific 
 * "1...10...0" block to turn it into "0...01...1".
 * 
 * Specifically, every contiguous block of '1's that is followed by at least one '0' 
 * contributes to the need for an operation. If we look at the string, every time 
 * the pattern "10" appears, it indicates a point where the sorted order is violated.
 * 
 * Let's count the number of occurrences of the pattern "10".
 * If we have a sequence like "11100", one reversal of the "11100" part makes it "00111".
 * If we have "1010", we have two "10" patterns.
 * The number of operations required is exactly the number of times the pattern "10" 
 * appears in the string.
 * 
 * Example 1: 000 -> "10" count = 0. Output 0.
 * Example 2: 1001 -> "10" appears at index 0. Count = 1. Output 1.
 * Example 3: 1010 -> "10" appears at index 0 and index 2. Count = 2. Output 2.
 * Example 4: 010101 -> "10" appears at index 1 and index 3. Count = 2. Output 2.
 * 
 * This logic holds because each "10" transition represents a boundary that must be 
 * resolved, and one reversal can effectively move a block of 1s past a block of 0s.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int operations = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1' && s[i + 1] == '0') {
            operations++;
        }
    }
    cout << operations << "\n";
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