#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In every 2 seconds (a cycle), Faizal moves 3 steps forward and 1 step backward.
 * Net displacement per 2 seconds = 3 - 1 = 2 steps.
 * 
 * If k is even:
 * There are k/2 full cycles.
 * Position = (k/2) * 2 = k.
 * 
 * If k is odd:
 * There are (k-1)/2 full cycles, plus one final forward step.
 * Position = ((k-1)/2) * 2 + 3 = (k-1) + 3 = k + 2.
 * 
 * Example check:
 * k=1: odd, pos = 1+2 = 3. Correct.
 * k=2: even, pos = 2. Correct.
 * k=5: odd, pos = 5+2 = 7. Correct.
 * k=11: odd, pos = 11+2 = 13. Correct.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long k;
        cin >> k;
        
        if (k == 0) {
            cout << 0 << "\n";
        } else if (k % 2 == 0) {
            // Even number of seconds: k/2 cycles of +2 displacement
            cout << k << "\n";
        } else {
            // Odd number of seconds: (k-1)/2 cycles of +2, plus 3 forward
            cout << (k + 2) << "\n";
        }
    }
    return 0;
}