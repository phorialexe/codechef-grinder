#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a binary string S of length N. We want to rearrange it to minimize the cost.
 * The cost is defined by:
 * - (number of "01" occurrences) * X
 * - (number of "10" occurrences) * Y
 * 
 * Let c0 be the count of '0's and c1 be the count of '1's in the string.
 * If we group all '0's together and all '1's together, we can have at most one "01" 
 * (if we arrange as 00...011...1) or at most one "10" (if we arrange as 11...100...0).
 * 
 * If the string contains no '0's or no '1's, the cost is 0.
 * If the string contains both '0's and '1's:
 * - Arranging as 00...011...1 results in one "01" and zero "10"s. Cost = X.
 * - Arranging as 11...100...0 results in one "10" and zero "01"s. Cost = Y.
 * 
 * Therefore, the minimum cost is min(X, Y) if both '0' and '1' are present,
 * and 0 if only one type of character is present.
 */

void solve() {
    int N, X, Y;
    cin >> N >> X >> Y;
    string S;
    cin >> S;

    bool hasZero = false;
    bool hasOne = false;

    for (char c : S) {
        if (c == '0') hasZero = true;
        if (c == '1') hasOne = true;
    }

    if (!hasZero || !hasOne) {
        cout << 0 << "\n";
    } else {
        cout << min(X, Y) << "\n";
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