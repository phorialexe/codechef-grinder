#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts serving from the right side.
 * He serves from the right side whenever his current score is even.
 * The sequence of scores when he serves from the right is: 0, 2, 4, 6, ..., up to P.
 * This is an arithmetic progression: 0, 2, 4, ..., 2k, where 2k <= P.
 * We need to find the number of terms in this sequence.
 * The terms are 2*0, 2*1, 2*2, ..., 2*k.
 * The number of terms is k + 1.
 * Since 2k <= P, k <= P/2.
 * The number of terms is floor(P/2) + 1.
 * 
 * Example 1: P = 2. Sequence: 0, 2. Count = 2. (2/2 + 1 = 2)
 * Example 2: P = 9. Sequence: 0, 2, 4, 6, 8. Count = 5. (9/2 + 1 = 4 + 1 = 5)
 * 
 * Complexity:
 * Time: O(1) per test case.
 * Space: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long p;
        cin >> p;
        
        // The number of times Chef serves from the right is floor(p / 2) + 1
        long long result = (p / 2) + 1;
        cout << result << "\n";
    }

    return 0;
}