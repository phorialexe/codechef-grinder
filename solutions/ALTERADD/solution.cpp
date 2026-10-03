#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operations are:
 * 1st: +1
 * 2nd: +2
 * 3rd: +1
 * 4th: +2
 * ...
 * Every pair of operations (1st and 2nd, 3rd and 4th, etc.) adds a total of 1 + 2 = 3 to A.
 * Let D = B - A.
 * We want to know if D can be represented as a sum of 1s and 2s following the alternating pattern.
 * 
 * If we perform k pairs of operations, we add 3*k.
 * After these pairs, we might perform one additional operation (+1).
 * So, D can be written as:
 * 1) D = 3k (if we stop after an even number of operations)
 * 2) D = 3k + 1 (if we stop after an odd number of operations)
 * 
 * This means D % 3 must be either 0 or 1.
 * If D % 3 == 2, it is impossible to reach B from A.
 */

void solve() {
    long long A, B;
    cin >> A >> B;
    long long diff = B - A;
    
    if (diff % 3 == 2) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
    }
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