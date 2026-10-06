#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N. We want to rearrange S to maximize
 * the length of the longest alternating substring.
 * 
 * Let c0 be the count of '0's and c1 be the count of '1's.
 * Without loss of generality, assume c0 <= c1.
 * We can place all c0 '0's such that they are separated by '1's.
 * For example, if we have c0 zeros, we can create an alternating sequence
 * of length 2 * c0 + 1 by placing a '1' between every '0' and adding a '1'
 * at both ends if possible.
 * 
 * Specifically:
 * - We have c0 zeros and c1 ones.
 * - We can form an alternating sequence by alternating 0s and 1s.
 * - If c0 == c1, we can use all characters to form an alternating string of length c0 + c1 = N.
 * - If c0 != c1, the maximum number of zeros we can use is c0, and the maximum number
 *   of ones we can use is c0 + 1 (by placing them as 10101...01).
 * - Thus, the length is 2 * c0 + 1 if c1 > c0.
 * - If c0 == c1, the length is 2 * c0 = N.
 * 
 * Combining these:
 * If c0 == c1, length = 2 * c0.
 * If c0 != c1, length = 2 * min(c0, c1) + 1.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int c0 = 0, c1 = 0;
    for (char c : S) {
        if (c == '0') c0++;
        else c1++;
    }

    if (c0 == c1) {
        cout << N << "\n";
    } else {
        cout << 2 * min(c0, c1) + 1 << "\n";
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