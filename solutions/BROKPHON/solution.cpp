#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A player i (1-indexed) is involved in a mistake if:
 * 1. The message they received (A[i]) is different from the message the previous player received (A[i-1]).
 *    In this case, player i misheard, or player i-1 whispered wrongly.
 * 2. The message they whispered (A[i]) is different from the message the next player received (A[i+1]).
 *    In this case, player i whispered wrongly, or player i+1 misheard.
 * 
 * Essentially, if A[i] != A[i+1], then both player i and player i+1 are part of a "broken" link.
 * We need to count the total number of unique players involved in at least one such broken link.
 * 
 * Let's use a boolean array 'is_broken' of size N to mark players.
 * For every i from 0 to N-2:
 *    If A[i] != A[i+1]:
 *        mark player i as broken
 *        mark player i+1 as broken
 * Finally, count the number of true values in the boolean array.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<bool> is_broken(N, false);
    for (int i = 0; i < N - 1; ++i) {
        if (A[i] != A[i + 1]) {
            is_broken[i] = true;
            is_broken[i + 1] = true;
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        if (is_broken[i]) {
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
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}