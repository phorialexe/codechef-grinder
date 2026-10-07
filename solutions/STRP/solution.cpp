#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to minimize the number of operations to transfer string S.
 * An operation can send 1 or 2 copies of the same character.
 * To minimize operations, we should greedily group identical consecutive characters.
 * If we have a block of 'k' identical characters, we can process them by taking 
 * as many pairs as possible.
 * Specifically, for a block of length 'k', we can use floor(k/2) operations of 
 * size 2, and if there is a remainder (k % 2 != 0), we use 1 operation of size 1.
 * Total operations for a block of length 'k' = (k / 2) + (k % 2).
 * This is equivalent to ceil(k / 2.0).
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    if (N == 0) {
        cout << 0 << "\n";
        return;
    }

    long long total_ops = 0;
    int i = 0;
    while (i < N) {
        int count = 0;
        char current_char = S[i];
        
        // Count the length of the current block of identical characters
        while (i < N && S[i] == current_char) {
            count++;
            i++;
        }
        
        // For a block of size 'count', we can send 2 characters per operation.
        // The number of operations is ceil(count / 2.0)
        total_ops += (count / 2) + (count % 2);
    }

    cout << total_ops << "\n";
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