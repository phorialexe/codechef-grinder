#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allowed is to swap any two characters in string S.
 * Swapping characters allows us to rearrange the string S into any permutation 
 * of its original characters.
 * 
 * A binary string consists only of '0's and '1's. If we can rearrange S into R,
 * it implies that the count of '0's in S must equal the count of '0's in R,
 * and the count of '1's in S must equal the count of '1's in R.
 * 
 * Since the total length N is fixed and the strings are binary, if the number 
 * of '1's is the same in both strings, the number of '0's must also be the same.
 * Therefore, the condition for S to be transformable into R is simply:
 * count('1' in S) == count('1' in R).
 */

void solve() {
    int N;
    cin >> N;
    string S, R;
    cin >> S >> R;

    int countS1 = 0;
    int countR1 = 0;

    for (char c : S) {
        if (c == '1') countS1++;
    }

    for (char c : R) {
        if (c == '1') countR1++;
    }

    if (countS1 == countR1) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}